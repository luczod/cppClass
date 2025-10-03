#include <string.h>
#include <stdio.h>
#include "controller.h"

static void controller_on_click(void *object);

bool controller_init(CONTROLLER_T *controller)
{
    bool status = false;

    if (controller != NULL)
    {
        memset(controller, 0, sizeof(CONTROLLER_T));

        controller->base.object = controller;
        controller->base.on_click = controller_on_click;

        status = true;
    }

    return status;
}

bool controller_open(CONTROLLER_T *controller, CONTROLLER_ARGS_T *args)
{
    bool status = true;

    if (controller != NULL && args != NULL)
    {
        controller->counter = args->counter;
        controller->view_base = args->view_base;

        status = true;
    }
    return status;
}

bool controller_run(CONTROLLER_T *controller)
{
    bool status = true;

    if (controller != NULL)
    {
        controller->view_base->set_text(controller->view_base->object, "0");
        controller->view_base->run(controller->view_base->object);
        status = true;
    }

    return status;
}

bool controller_close(CONTROLLER_T *controller)
{
    bool status = true;

    if (controller != NULL)
    {
        memset(controller, 0, sizeof(CONTROLLER_T));
        status = true;
    }

    return status;
}

void controller_on_click(void *object)
{
    CONTROLLER_T *controller = (CONTROLLER_T *)object;

    char buffer[1024] = {0};
    counter_increment(controller->counter, 1);
    snprintf(buffer, 1024, "%d", counter_get_value(controller->counter));

    controller->view_base->set_text(controller->view_base->object, buffer);
}
