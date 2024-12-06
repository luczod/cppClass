#include <iostream>
#include <stack>
using namespace std;

struct Point_3D
{
    int x, y, z;
    Point_3D(int x = 0, int y = 0, int z = 0)
    {
        this->x = x, this->y = y, this->z = z;
    }
};


void emplace_example()
{
    stack<Point_3D> multiverse;

    // First, Object of that(multiverse) class has to be created, then it's added to the stack/queue
    Point_3D pt {32, -2452};
    multiverse.push(pt);

    // Here, no need to create object, emplace will do the honors
    multiverse.emplace(32, -2452);

    multiverse.emplace(455, -3);
    multiverse.emplace(129, 4, -67);
}