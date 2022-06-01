#include "../desktop_settings/desktop_settings.h"
#include "../views/desktop_events.h"
#include <gui/view.h>

typedef struct DesktopViewGame DesktopViewGame;

typedef void (*DesktopViewGameCallback)(DesktopEvent event, void* context);

void desktop_view_game_set_callback(
    DesktopViewGame* game_view,
    DesktopViewGameCallback callback,
    void* context);

void desktop_view_game_update(DesktopViewGame* game_view);
View* desktop_view_game_get_view(DesktopViewGame* game_view);
DesktopViewLocked* desktop_view_locked_alloc();
void desktop_view_game_free(DesktopViewGame* game_view);