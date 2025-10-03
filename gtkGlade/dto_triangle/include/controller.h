#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "controller_base.h"
#include "view_base.h"
#include "model.h"

typedef struct
{
    CONTROLLER_BASE_T base;
    VIEW_BASE_T *view;
    TRIANGLE_T *triangle;
} CONTROLLER_T;

typedef struct
{
    VIEW_BASE_T *view;
    TRIANGLE_T *triangle;
} CONTROLLER_ARGS_T;

bool controller_init(CONTROLLER_T *con);
bool controller_open(CONTROLLER_T *con, CONTROLLER_ARGS_T *args);
bool controller_run(CONTROLLER_T *con);
bool controller_close(CONTROLLER_T *con);

#endif /* CONTROLLER_H */