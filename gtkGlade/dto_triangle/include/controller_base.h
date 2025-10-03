#ifndef CONTROLLER_BASE_H
#define CONTROLLER_BASE_H

typedef struct
{
    void *object;
    void (*on_submit)(void *object);
    void (*on_change)(void *object);
} CONTROLLER_BASE_T;

#endif /* CONTROLLER_BASE_H */