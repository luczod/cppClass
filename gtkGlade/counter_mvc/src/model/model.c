#include <string.h>
#include "model/model.h"

bool counter_init(COUNTER_T *counter)
{
    bool status = false;

    if (counter != NULL)
    {
        memset(counter, 0, sizeof(COUNTER_T));
        status = true;
    }

    return status;
}

bool counter_increment(COUNTER_T *counter, int step)
{
    bool status = false;

    if (counter != NULL)
    {
        counter->value += step;
        status = true;
    }

    return status;
}

int counter_get_value(COUNTER_T *counter)
{
    int value = -1;

    if (counter != NULL)
    {
        value = counter->value;
    }

    return value;
}
