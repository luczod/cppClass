#ifndef MODEL_H
#define MODEL_H

#include <stdbool.h>

typedef struct
{
    int side_a;
    int side_b;
    int side_c;
} TRIANGLE_T;

TRIANGLE_T triangle_create(int side_a, int side_b, int side_c);
bool is_triangle_equilateral(TRIANGLE_T *t);
bool is_triangle_isosceles(TRIANGLE_T *t);
bool is_triangle_scalene(TRIANGLE_T *t);
bool is_triangle_exists(TRIANGLE_T *t);

#endif /* MODEL_H */