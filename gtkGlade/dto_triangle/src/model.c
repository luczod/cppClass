#include "model.h"

TRIANGLE_T triangle_create(int side_a, int side_b, int side_c)
{
    TRIANGLE_T t =
        {
            .side_a = side_a,
            .side_b = side_b,
            .side_c = side_c,
        };

    return t;
}

bool is_triangle_equilateral(TRIANGLE_T *t)
{
    return (t->side_a == t->side_b && t->side_a == t->side_c);
}

bool is_triangle_isosceles(TRIANGLE_T *t)
{
    bool status = false;

    status |= ((t->side_a == t->side_b) && (t->side_b != t->side_c));
    status |= ((t->side_b == t->side_c) && (t->side_c != t->side_a));
    status |= ((t->side_a == t->side_c) && (t->side_a != t->side_b));

    return status;
}
bool is_triangle_scalene(TRIANGLE_T *t)
{
    return ((t->side_a != t->side_b) && (t->side_b != t->side_c) && (t->side_a != t->side_c));
}
bool is_triangle_exists(TRIANGLE_T *t)
{
    return !((t->side_a + t->side_b > t->side_c) &&
             (t->side_b + t->side_c > t->side_b) &&
             (t->side_c + t->side_a > t->side_b));
}
