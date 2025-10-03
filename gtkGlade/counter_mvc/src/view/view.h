#ifndef VIEW_H
#define VIEW_H

#include <stdbool.h>
#include "view_base.h"
#include "controller/controller_base.h"

typedef struct WIDGETS_T
{
    void *window;
    void *txt_counter;
    void *bt_counter;
} WIDGETS_T;

typedef struct VIEW_T
{
    VIEW_BASE_T base;
    CONTROLLER_BASE_T *constroller_base;
    WIDGETS_T *widgets;
    int argc;
    char **argv;
} VIEW_T;

typedef struct VIEW_ARGS_T
{
    CONTROLLER_BASE_T *constroller_base;
    int argc;
    char **argv;
} VIEW_ARGS_T;

bool view_init(VIEW_T *view);
bool view_open(VIEW_T *view, VIEW_ARGS_T *args);
bool view_close(VIEW_T *view);

#endif /* VIEW_H */