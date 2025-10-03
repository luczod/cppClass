#ifndef CONTROLLER_BASE_H
#define CONTROLLER_BASE_H

typedef struct
{
    void *object;
    void (*on_click)(void *object);
    void (*run)(void *object);
} CONTROLLER_BASE_T;

#endif /* CONTROLLER_BASE_H */