#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "controller/controller_base.h"
#include "view/view_base.h"
#include "model/model.h"

typedef struct CONTROLLER_T
{
    CONTROLLER_BASE_T base;
    VIEW_BASE_T *view_base;
    COUNTER_T *counter;
} CONTROLLER_T;

typedef struct CONTROLLER_ARGS_T
{
    VIEW_BASE_T *view_base;
    COUNTER_T *counter;
} CONTROLLER_ARGS_T;

bool controller_init(CONTROLLER_T *controller);
bool controller_open(CONTROLLER_T *controller, CONTROLLER_ARGS_T *args);
bool controller_run(CONTROLLER_T *controller);
bool controller_close(CONTROLLER_T *controller);

#endif /* CONTROLLER_H */