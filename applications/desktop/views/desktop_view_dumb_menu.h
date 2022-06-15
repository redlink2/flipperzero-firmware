#pragma once

#include <gui/view.h>
#include "desktop_events.h"

typedef struct DesktopDumbMenuView DesktopDumbMenuView;

typedef void (*DesktopDumbMenuViewCallback)(DesktopEvent event, void* context);

struct DesktopDumbMenuView {
    View* view;
    DesktopDumbMenuViewCallback callback;
    void* context;
);

typedef struct {
    uint8_t idx;
} DesktopDumbMenuViewModel;

void desktop_dumb_menu_set_callback(
    DesktopDumbMenuView* dumb_menu,
    DesktopDumbMenuViewCallback callback,
    void* context);

View* desktop_dumb_menu_get_view(DesktopDumbMenuView* dumb_menu);
void desktop_dumb_menu_set_idx(DesktopDumbMenuView* dumb_menu, uint8_t idx);
DesktopDumbMenuView* desktop_dumb_menu_alloc();
void desktop_dumb_menu_free(DesktopDumbMenuView* dumb_menu);