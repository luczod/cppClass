// Section 21
// Function Objects
#include <algorithm>
// #include <functional>
#include <iostream>
#include <vector>

struct Square_Functor {
    // Overloading operator "()", function call operator
    void operator()(int x)
    {
        std::cout << x * x << " ";
    }
};

template <typename T>
struct Displayer {
    // Function Objects
    // Overloading operator "()", function call operator
    void operator()(const T &data)
    {
        std::cout << data << " ";
    }
};

class Multiplier
{
private:
    int num{};

public:
    Multiplier(int n)
        : num{ n }
    {
    }
    // Function Objects
    // Overloading operator "()", function call operator
    int operator()(int n) const
    {
        return n * num;
    }
};

// Global variables
Displayer<int> d1;
Displayer<std::string> d2;
Square_Functor square;

std::vector<int> vec1{ 1, 2, 3, 4, 5 };
std::vector<std::string> vec2{ "Larry", "Moe", "Curly" };

void test1()
{

    std::cout << "\nTest1 =================" << std::endl;
    square(4); // square.operator()(4) , Function Objects

    d1(100);     // displays 100
    d2("Frank"); // displays Frank
}

void test2()
{

    Displayer<int> d1;
    Displayer<std::string> d2;
    Square_Functor square;

    std::cout << "\n\nTest2 =================" << std::endl;
    std::vector<int> vec1{ 1, 2, 3, 4, 5 };
    std::vector<std::string> vec2{ "Larry", "Moe", "Curly" };

    std::for_each(vec1.begin(), vec1.end(), square); // 1 4 9 16 25
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), Displayer<int>()); // 1 2 3 4 5
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), d1); // 1 2 3 4 5
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), Displayer<std::string>()); // Larry Moe Curly
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), d2); // Larry Moe Curly
    std::cout << std::endl;
}

void test3()
{

    std::cout << "\nTest3 =================" << std::endl;
    std::for_each(vec1.begin(), vec1.end(),
                  [](int x) { std::cout << x * x << " "; }); // 1 4 9 16 25

    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(),
                  [](int x) { std::cout << x * 10 << " "; }); // 10 20 30 40 50

    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), [](int x) { std::cout << x << " "; }); // 1 2 3 4 5
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(),
                  [](std::string s) { std::cout << s << " "; }); // Larry Moe Curly

    std::cout << std::endl;
}

void test4()
{

    std::cout << "\nTest4 =================" << std::endl;
    Multiplier mult(100); // Function Objects
    vec1 = { 1, 2, 3, 4 };

    // transform changes the vector!
    // Function Objects, multi
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), mult);
    std::for_each(vec1.begin(), vec1.end(), d1); // 100 200 300 400
    std::cout << std::endl;

    vec1 = { 1, 2, 3, 4 };
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), [](int x) { return x * 100; });
    std::for_each(vec1.begin(), vec1.end(),
                  [](int x) { std::cout << x << " "; }); // 100 200 300 400 500

    std::cout << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();

    return 0;
}
