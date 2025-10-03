#ifndef MODEL_H
#define MODEL_H

#include <stdbool.h>

typedef struct
{
    int value;
} COUNTER_T;

bool counter_init(COUNTER_T *counter);
bool counter_increment(COUNTER_T *counter, int step);
int counter_get_value(COUNTER_T *counter);

#endif /* MODEL_H */