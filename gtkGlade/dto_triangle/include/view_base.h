#ifndef VIEW_BASE_H
#define VIEW_BASE_H

#include <stdbool.h>
#include "model_dto.h"

typedef struct
{
    void *object;
    TRIANGLE_DTO_T (*get_triangle_dto)(void *object);
    void (*set_triangle_result)(void *object, const char *message);
    bool (*run)(void *object);
} VIEW_BASE_T;

#endif /* VIEW_BASE_H */