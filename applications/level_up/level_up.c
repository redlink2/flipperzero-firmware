#include <furi.h>
#include <dialogs/dialogs.h>
#include <gui/gui.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/empty_screen.h>
#include <m-string.h>
#include <furi_hal_version.h>
#include "dolphin/helpers/dolphin_deed.h"
#include "dolphin/helpers/dolphin_state.h"
#include <dolphin/dolphin.h>

#define LEVEL2_THRESHOLD 735
#define LEVEL3_THRESHOLD 2940

typedef DialogMessageButton (*AboutDialogScreen)(DialogsApp* dialogs, DialogMessage* message);

static DialogMessageButton welcome_screen(DialogsApp* dialogs, DialogMessage* message) {
    DialogMessageButton result;
    string_t buffer;
    string_init(buffer);

    Dolphin* dolphin = furi_record_open("dolphin");
    DolphinStats stats = dolphin_stats(dolphin);
    furi_record_close("dolphin");

    //char buffer2[10];
    //snprintf(buffer2, 10, "%d", stats.level);
    string_cat_printf(buffer, "%s%d", "Current Level: ", stats.level);

    const char* screen_header = "Welcome to\n"
                                "Dolphin Level Hacker\n";
    //const char* screen_text = "Current Level: \n";

    dialog_message_set_header(message, screen_header, 0, 0, AlignLeft, AlignTop);
    //dialog_message_set_text(message, screen_text, 0, 26, AlignLeft, AlignTop);
    dialog_message_set_text(message, string_get_cstr(buffer), 0, 26, AlignLeft, AlignTop);
    result = dialog_message_show(dialogs, message);
    dialog_message_set_header(message, NULL, 0, 0, AlignLeft, AlignTop);
    dialog_message_set_text(message, NULL, 0, 0, AlignLeft, AlignTop);

    return result;
}

static DialogMessageButton detailed_screen(DialogsApp* dialogs, DialogMessage* message) {
    DialogMessageButton result;
    string_t buffer;
    string_init(buffer);

    Dolphin* dolphin = furi_record_open("dolphin");
    DolphinStats stats = dolphin_stats(dolphin);
    furi_record_close("dolphin");

    // Calcualte
    uint32_t remainingXP = 0;
    if(stats.icounter <= LEVEL2_THRESHOLD) {
        remainingXP = LEVEL2_THRESHOLD - stats.icounter;
    } else if(stats.icounter <= LEVEL3_THRESHOLD) {
        remainingXP = LEVEL3_THRESHOLD - stats.icounter;
    } else {
        remainingXP = 0;
    }
    // dolphin_state_xp_to_levelup

    string_cat_printf(
        buffer,
        "%s%d\n%s%d\n%s%d",
        "Current Level: ",
        stats.level,
        "Current XP: ",
        stats.icounter,
        "XP to Next Level: ",
        remainingXP);

    const char* screen_header = "Extended Stats";

    dialog_message_set_header(message, screen_header, 0, 0, AlignLeft, AlignTop);
    dialog_message_set_text(message, string_get_cstr(buffer), 0, 14, AlignLeft, AlignTop);
    result = dialog_message_show(dialogs, message);
    dialog_message_set_header(message, NULL, 0, 0, AlignLeft, AlignTop);
    dialog_message_set_text(message, NULL, 0, 0, AlignLeft, AlignTop);

    return result;
}

static DialogMessageButton level_1_screen(DialogsApp* dialogs, DialogMessage* message) {
    DialogMessageButton result;

    const char* screen_text = "Set Dolphin to Level 1\n"
                              "Push 'BACK' button to set!\n";

    //DOLPHIN_DEED(DolphinDeedSubGhzSave);

    dialog_message_set_text(message, screen_text, 0, 0, AlignLeft, AlignTop);
    result = dialog_message_show(dialogs, message);
    dialog_message_set_text(message, NULL, 0, 0, AlignLeft, AlignTop);

    return result;
}

static DialogMessageButton level_2_screen(DialogsApp* dialogs, DialogMessage* message) {
    DialogMessageButton result;

    // Dolphin* dolphin = furi_record_open("dolphin");
    // furi_record_close("dolphin");

    // dolphin_upgrade_level(dolphin->state);

    const char* screen_text = "Set Dolphin to Level 2\n"
                              "Push 'BACK' button to set!\n";

    dialog_message_set_text(message, screen_text, 0, 0, AlignLeft, AlignTop);
    result = dialog_message_show(dialogs, message);
    dialog_message_set_text(message, NULL, 0, 0, AlignLeft, AlignTop);

    return result;
}

static DialogMessageButton level_3_screen(DialogsApp* dialogs, DialogMessage* message) {
    DialogMessageButton result;

    const char* screen_text = "Set Dolphin to Level 3\n"
                              "Push 'BACK' button to set!\n";

    dialog_message_set_text(message, screen_text, 0, 0, AlignLeft, AlignTop);
    result = dialog_message_show(dialogs, message);
    dialog_message_set_text(message, NULL, 0, 0, AlignLeft, AlignTop);

    return result;
}

const AboutDialogScreen level_up_screens[] =
    {welcome_screen, detailed_screen, level_1_screen, level_2_screen, level_3_screen};

const size_t level_up_screens_count = sizeof(level_up_screens) / sizeof(AboutDialogScreen);

int32_t level_up_app(void) {
    DialogsApp* dialogs = furi_record_open("dialogs");
    DialogMessage* message = dialog_message_alloc();

    Gui* gui = furi_record_open("gui");
    ViewDispatcher* view_dispatcher = view_dispatcher_alloc();
    EmptyScreen* empty_screen = empty_screen_alloc();
    const uint32_t empty_screen_index = 0;

    size_t screen_index = 0;
    DialogMessageButton screen_result;

    // draw empty screen to prevent menu flickering
    view_dispatcher_add_view(
        view_dispatcher, empty_screen_index, empty_screen_get_view(empty_screen));
    view_dispatcher_attach_to_gui(view_dispatcher, gui, ViewDispatcherTypeFullscreen);
    view_dispatcher_switch_to_view(view_dispatcher, empty_screen_index);

    while(1) {
        if(screen_index >= level_up_screens_count - 1) {
            dialog_message_set_buttons(message, "Back", NULL, NULL);
        } else {
            dialog_message_set_buttons(message, "Back", NULL, "Next");
        }

        screen_result = level_up_screens[screen_index](dialogs, message);

        if(screen_result == DialogMessageButtonLeft) {
            if(screen_index <= 0) {
                break;
            } else {
                screen_index--;
            }
        } else if(screen_result == DialogMessageButtonRight) {
            if(screen_index < level_up_screens_count) {
                screen_index++;
            }
        } else if(screen_result == DialogMessageButtonBack) {
            break;
        }
    }

    dialog_message_free(message);
    furi_record_close("dialogs");

    view_dispatcher_remove_view(view_dispatcher, empty_screen_index);
    view_dispatcher_free(view_dispatcher);
    empty_screen_free(empty_screen);
    furi_record_close("gui");

    return 0;
}