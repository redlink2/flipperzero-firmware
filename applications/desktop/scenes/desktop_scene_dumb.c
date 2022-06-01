#include <furi.h>
#include <furi_hal.h>
#include <gui/scene_manager.h>
#include <gui/view_stack.h>
#include "../desktop.h"
#include "../desktop_i.h"
#include "../views/desktop_events.h"
#include "desktop_scene.h"
#include "desktop_scene_i.h"

#include "../desktop_settings/desktop_settings.h"
#include "../desktop_i.h"
#include "desktop_view_dumb.h"

static void desktop_scene_dumb_callback(DesktopEvent event, void* context) {
    Desktop* desktop = (Desktop*)context;
    view_dispatcher_send_custom_event(desktop->view_dispatcher, event);
}

static void desktop_scene_dumb_new_idle_animation_callback(void* context) {
    furi_assert(context);
    Desktop* desktop = context;
    view_dispatcher_send_custom_event(
        desktop->view_dispatcher, DesktopAnimationEventNewIdleAnimation);
}

void desktop_scene_game_on_enter(void* context) {
    Desktop* desktop = (Desktop*)context;

    // callbacks for the view dispatcher
}

bool desktop_scene_game_on_event(void* context, SceneManagerEvent event) {
    Desktop* desktop = (Desktop*)context;
    bool consumed = false;

    // event handling
    if(event.type == SceneManagerEventTypeCustom) {
        switch(event.event) {
            case DesktopLockedEventUnlocked:
                break;
            }
    }

    return consumed;
}

void desktop_scene_game_on_exit(void* context) {
    UNUSED(context);
}