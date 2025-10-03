#ifndef VIEW_BASE_H
#define VIEW_BASE_H

typedef struct
{
    void *object;
    void (*set_text)(void *object, const char *text);
    void (*run)(void *object);
} VIEW_BASE_T;

#endif /* VIEW_BASE_H */