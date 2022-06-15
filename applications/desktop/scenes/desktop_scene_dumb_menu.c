#include <gui/scene_manager.h>
#include <applications.h>
#include <furi_hal.h>
#include <toolbox/saved_struct.h>
#include <stdbool.h>
#include <loader/loader.h>

#include "../desktop_i.h"
#include "../desktop_settings/desktop_settings.h"
#include "../views/desktop_view_dumb_menu.h"
#include "../views/desktop_view_main.h"
#include "desktop_scene_i.h"
#include "desktop_scene.h"

void desktop_scene_dumb_menu_callback(DesktopEvent event, void* context) {
    Desktop* desktop = (Desktop*)context;
    view_dispatcher_send_custom_event(desktop->view_dispatcher, event);
}

void desktop_scene_dumb_menu_on_enter(void* context) {
    Desktop* desktop = (Desktop*)context;

    LOAD_DESKTOP_SETTINGS(&desktop->settings);
    scene_manager_set_scene_state(desktop->scene_manager, DesktopSceneDumbMenu, 0);
    desktop_dumb_menu_set_callback(desktop->dumb_menu, desktop_scene_dumb_menu_callback, desktop);
    desktop_dumb_menu_set_idx(desktop->dumb_menu, 0);

    view_dispatcher_switch_to_view(desktop->view_dispatcher, DesktopViewIdDumbMenu);
}

bool desktop_scene_dumb_menu_on_event(void* context, SceneManagerEvent event) {
    // Desktop* desktop = (Desktop*)context;
    Desktop* desktop = context;
    bool consumed = false;

    if(event.type == SceneManagerEventTypeCustom) {
        switch(event.event) {
        case DesktopDumbMenuEventGames:
            desktop->callback(DesktopDumbMenuEventGames, desktop->context);
            consumed = true;
            break;
        case DesktopDumbMenuEventApps:
            consumed = true;
            break;
        case DesktopLockMenuEventExit:
            scene_manager_search_and_switch_to_previous_scene(
                desktop->scene_manager, DesktopSceneMain);
            consumed = true;
            break;
        default:
            break;
        }
    }
    return consumed;
}

void desktop_scene_lock_menu_on_exit(void* context) {
    UNUSED(context);
}