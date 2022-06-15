#include <furi.h>
#include <gui/elements.h>

#include "../desktop_i.h"
#include "desktop_view_dumb_menu.h"

#define DUMB_ITEMS_NB 3

void desktop_dumb_set_callback(
    DesktopDumbMenuView* dumb_menu,
    DesktopDumbMenuViewCallback callback,
    void* context) {
    furi_assert(dumb_menu);
    furi_assert(callback);
    dumb_menu->callback = callback;
    dumb_menu->context = context;
)

// void desktop_dumb_menu_set_idx(DesktopDumbMenuView* dumb_menu, uint8_t idx) {
//     furi_assert(idx < DUMB_ITEMS_NB);
//     with_view_model(
//         dumb_menu->view, (DesktopDumbMenuViewModel * model) {
//             model->idx = idx;
//             return true;
//         });
// }

static void dumb_menu_callback(void* context, uint8_t index) {
    furi_assert(context);
    DesktopDumbMenuView* dumb_menu = context;
    switch(index) {
    case 0: // games
        dumb_menu->callback(DesktopDumbMenuEventGames, dumb_menu->context);
        break;
    case 1: // apps
        dumb_menu->callback(DesktopDumbMenuEventApps, dumb_menu->context);
        break;
    case 2: // exit
        dumb_menu->callback(DesktopDumbMenuEventExit, dumb_menu->context);
        break;
    default: // message
        break;
    }
}

void dumb_menu_render(Canvas* canvas, void* model) {
    const char* Dumbmenu_Items[DUMB_ITEMS_NB] = {"Games", "Apps", "Exit"};

    DesktopDumbMenuViewModel* m = model;
    canvas_clear(canvas);
    canvas_set_color(canvas, ColorBlack);
    canvas_set_font(canvas, FontSecondary);

    for(uint8_t i = 0; i < DUMB_ITEMS_NB; ++i) {
        const char* str = Dumbmenu_items[i];

        if(str != NULL)
            canvas_draw_str_aligned(
                canvas, 64, 9 + (i * 17) + STATUS_BAR_Y_SHIFT, AlignCenter, AlignCenter, str);

        if(m->idx == i) elements_frame(canvas, 15, 1 + (i * 17) + STATUS_BAR_Y_SHIFT, 98, 15);
    }
}

View* desktop_dumb_menu_get_view(DesktopDumbMenuView* dumb_menu) {
    furi_assert(dumb_menu);
    return lock_menu->view;
}

bool desktop_dumb_menu_input(InputEvent* event, void* context) {
    furi_assert(event);
    furi_assert(context);

    DesktopDumbMenuView* dumb_menu = context;
    uint8_t idx = dumb_menu->idx;

    if(event->type != InputTypeShort) return false;
    with_view_model(
        dumb_menu->view, (DesktopLockMenuViewModel * model) {
            model->hint_timeout = 0; // clear hint timeout
            if(event->key == InputKeyUp) {
                model->idx = CLAMP(model->idx - 1, DUMB_ITEMS_NB - 1, 0);
            } else if(event->key == InputKeyDown) {
                model->idx = CLAMP(model->idx + 1, DUMB_ITEMS_NB - 1, 0);
            }
            idx = model->idx;
            return true;
        });

    if(event->key == InputKeyBack) {
        dumb_menu->callback(DesktopDumbMenuEventExit, dumb_menu->context);
    } else if(event->key == InputKeyOk) {
        dumb_menu_callback(dumb_menu, idx);
    }

    return true;
}

DesktopDumbMenuView* desktop_dumb_menu_alloc() {
    DesktopDumbMenuView* dumb_menu = malloc(sizeof(DesktopDumbMenuView));
    dumb_menu->view = view_alloc();
    view_allocate_model(dumb_menu->view, ViewModelTypeLocking, sizeof(DesktopDumbMenuViewModel));
    view_set_context(dumb_menu->view, dumb_menu);
    view_set_draw_callback(dumb_menu->view, (ViewDrawCallback)dumb_menu_render);
    view_set_input_callback(dumb_menu->view, desktop_dumb_menu_input);

    return dumb_menu;
}

void desktop_dumb_menu_free(DesktopDumbMenuView* dumb_menu_view) {
    furi_assert(dumb_menu_view);
    view_free(dumb_menu_view->view);
    free(dumb_menu_view);
}