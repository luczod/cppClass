#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "controller.h"
#include "business.h"

static void controller_on_submit(void *object);
static void controller_on_change(void *object);

bool controller_init(CONTROLLER_T *con)
{
    bool status = false;

    if (con != NULL)
    {
        memset(con, 0, sizeof(CONTROLLER_T));

        con->base.object = con;
        con->base.on_change = controller_on_change;
        con->base.on_submit = controller_on_submit;

        status = true;
    }

    return status;
}

bool controller_open(CONTROLLER_T *con, CONTROLLER_ARGS_T *args)
{
    bool status = false;

    if (con != NULL && args != NULL)
    {

        con->triangle = args->triangle;
        con->view = args->view;

        status = true;
    }

    return status;
}

bool controller_run(CONTROLLER_T *con)
{
    bool status = false;

    if (con != NULL)
    {
        con->view->run(con->view->object);
        status = true;
    }

    return status;
}

bool controller_close(CONTROLLER_T *con)
{
    bool status = false;

    if (con != NULL)
    {
        memset(con, 0, sizeof(CONTROLLER_T));
        status = true;
    }

    return status;
}

static void controller_on_submit(void *object)
{
    char *message = NULL;
    CONTROLLER_T *con = (CONTROLLER_T *)object;
    con->view->set_triangle_result(con->view->object, "");
    TRIANGLE_DTO_T dto = con->view->get_triangle_dto(con->view->object);

    con->triangle->side_a = atoi(dto.side_a);
    con->triangle->side_b = atoi(dto.side_b);
    con->triangle->side_c = atoi(dto.side_c);

    message = (char *)business_get_message(con->triangle);
    con->view->set_triangle_result(con->view->object, message);
}

static void controller_on_change(void *object)
{
}
