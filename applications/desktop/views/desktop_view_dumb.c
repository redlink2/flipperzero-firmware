#include <furi.h>
#include <gui/elements.h>
#include <gui/icon.h>
#include <gui/view.h>

#include "../desktop_settings/desktop_settings.h"
#include "../desktop_i.h"
#include "desktop_view_dumb.h"


typedef enum {
    DesktopViewGameStateUnlocked,
    DesktopViewGameStateLocked,
} DesktopViewGameState;

typedef struct {
    DesktopViewGameState view_state;
} DesktopViewGameModel;

void desktop_view_dumb_set_callback(
    DesktopViewGame* game_view,
    DesktopViewGameCallback callback,
    void* context) {
    furi_assert(game_view);
    furi_assert(callback);
    game_view->callback = callback;
    game_view->context = context;
}

DesktopViewGame* desktop_view_game_alloc() {
    DesktopViewGame* game_view = furi_malloc(sizeof(DesktopViewGame));
    game_view->view = view_alloc();
    view_allocate_model(game_view->view, ViewModelTypeLocking, sizeof(DesktopViewGameModel));
    view_set_context(game_view->view, game_view);
    // view_set_draw_callback(dumb_view->view, desktop_view_locked_draw);
    // view_set_input_callback(dumb_view->view, desktop_view_locked_input);
    return game_view;
}

void desktop_view_game_free(DesktopViewGame* game_view) {
    furi_assert(game_view);
    view_free(game_view->view);
    free(game_view->view);
}