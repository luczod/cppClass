#include "controller/controller.h"
#include "view/view.h"
#include "model/model.h"

int main(int argc, char *argv[])
{
    VIEW_T view;
    CONTROLLER_T controller;
    COUNTER_T counter;

    VIEW_ARGS_T view_args;
    CONTROLLER_ARGS_T controller_args;

    counter_init(&counter);
    view_init(&view);
    controller_init(&controller);

    view_args.argc = argc;
    view_args.argv = argv;
    view_args.constroller_base = &controller.base;
    view_open(&view, &view_args);

    controller_args.counter = &counter;
    controller_args.view_base = &view.base;
    controller_open(&controller, &controller_args);
    controller_run(&controller);

    controller_close(&controller);
    view_close(&view);

    return 0;
}
