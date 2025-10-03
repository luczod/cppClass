#include "controller.h"
#include "view.h"
#include "model.h"

int main(int argc, char *argv[])
{
    VIEW_T view;
    TRIANGLE_T triangle;
    CONTROLLER_T controller;

    view_init(&view);
    controller_init(&controller);

    VIEW_ARGS_T view_args = {
        .argc = argc,
        .argv = argv,
        .con = &controller.base,
    };

    CONTROLLER_ARGS_T con_args = {
        .triangle = &triangle,
        .view = &view.base,
    };

    view_open(&view, &view_args);
    controller_open(&controller, &con_args);

    controller_run(&controller);

    view_close(&view);
    controller_close(&controller);

    return 0;
}