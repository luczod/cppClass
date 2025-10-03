#include "business.h"

typedef bool (*is_valid_t)(TRIANGLE_T *t);

typedef struct
{
    is_valid_t cb;
    const char *message;
} VAJLIDATION_RULES_T;

static VAJLIDATION_RULES_T rules[] = {
    {.cb = is_triangle_exists, .message = "Triangle do not exist"},
    {.cb = is_triangle_equilateral, .message = "Triangle is equilateral"},
    {.cb = is_triangle_isosceles, .message = "Triangle is isosceles"},
    {.cb = is_triangle_scalene, .message = "Triangle is scalene"},
};

static const int rules_amount = sizeof(rules) / sizeof(rules[0]);

const char *business_get_message(TRIANGLE_T *t)
{
    int i;
    for (i = 0; i < rules_amount; i++)
    {
        if (rules[i].cb(t) == true)
        {
            break;
        }
    }

    return rules[i].message;
}
