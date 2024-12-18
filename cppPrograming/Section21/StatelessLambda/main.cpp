// Section 21
// Stateless lambda expressions
// [] - empty capture lists
#include <algorithm>
#include <functional> // for std::function
#include <iostream>
#include <string>
#include <vector>

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);

private:
    std::string name;
    int age;

public:
    Person(std::string name, int age)
        : name{ name }
        , age{ age } {};

    // copy constructor
    Person(const Person &p)
        : name{ p.name }
        , age{ p.age } {};

    ~Person() = default;

    std::string get_name() const
    {
        return name;
    }

    void set_name(std::string name)
    {
        this->name = name;
    }

    int get_age() const
    {
        return age;
    }

    void set_age(int age)
    {
        this->age = age;
    }
};

std::ostream &operator<<(std::ostream &os, const Person &rhs)
{
    os << "[Person: " << rhs.name << " : " << rhs.age << "]";
    return os;
}

void test1()
{
    std::cout << "\n---Test1 --------------------------" << std::endl;

    []() { std::cout << "Hi" << std::endl; }();

    [](int x) { std::cout << x << std::endl; }(100); // call labmda funtion, x = 100

    [](int x, int y) { std::cout << x + y << std::endl; }(100, 200); // x = 100, y = 200
}

// Using values and references as lambda parameters
void test2()
{
    std::cout << "\n---Test2 --------------------------" << std::endl;

    auto lamba1 = []() { std::cout << "Hi" << std::endl; };
    lamba1();

    int num1{ 100 };
    int num2{ 100 };

    auto lamba2 = [](int x, int y) { std::cout << x + y << std::endl; };
    lamba2(10, 20);
    lamba2(num1, num2);

    auto lambda3 = [](int &x, int y) {
        std::cout << "x: " << x << " y: " << y << std::endl;
        x = 1000;
        y = 2000;
    };

    lambda3(num1, num2);
    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;
}

// Using value and reference objects as lambda parameters
void test3()
{
    std::cout << "\n---Test3 --------------------------" << std::endl;
    Person stooge{ "Larry", 18 };
    std::cout << stooge << std::endl;
    // passing parameter by value, thus uses copy constructor
    auto lambda4 = [](Person p) { std::cout << p << std::endl; };
    lambda4(stooge);

    // passing parameter by ref, No copy constructor
    // const, can't modify
    auto lambda5 = [](const Person &p) { std::cout << p << std::endl; };
    lambda5(stooge);

    // passing parameter by ref, No copy constructor
    auto lambda6 = [](Person &p) {
        p.set_name("Frank");
        p.set_age(25);
        std::cout << p << std::endl;
    };
    lambda6(stooge);

    std::cout << stooge << std::endl;
}

// used for test4
// using std::function as a parameter in C++14 and greater
// or
// auto as parameter type in C++20
void filter_vector(const std::vector<int> &vec, std::function<bool(int)> func)
{ // void filter_vector (const std::vector<int>  &vec, auto func) { c++20
    if(vec.empty()) {
        std::cout << "[]";
        return;
    }

    std::cout << "[ ";

    for(int i : vec) {
        if(func(i)) {
            std::cout << i << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

// passing a lambda to a function
void test4()
{
    std::cout << "\n---Test4 --------------------------" << std::endl;
    std::vector<int> nums{ 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

    filter_vector(nums, [](int x) { return x > 50; });

    filter_vector(nums, [](int x) { return x <= 30; });

    filter_vector(nums, [](int x) { return x >= 30 && x <= 60; });
}

// used for test5
auto make_lambda()
{
    return
        []() { std::cout << "This lambda was made using the make_lambda function!" << std::endl; };
}

// returning a lambda from a function
void test5()
{
    std::cout << "\n---Test5 --------------------------" << std::endl;

    auto lambda5 = make_lambda();

    lambda5();
}

// using auto in the lambda parameter list
void test6()
{
    std::cout << "\n---Test6 --------------------------" << std::endl;
    auto lambda6 = [](auto x, auto y) { std::cout << "x: " << x << " y: " << y << std::endl; };

    lambda6(10, 20);
    lambda6(100.3, 200);
    lambda6(12.5, 15.54);

    lambda6(Person("Larry", 18), Person("Curly", 22));
}

// Simple lambda examples with std::sort and std::for_each
void test7()
{
    std::cout << "\n---Test7 --------------------------" << std::endl;
    std::vector<Person> stooges{ { "Larry", 18 }, { "Moe", 30 }, { "Curly", 25 } };

    // begin(stooges) or stooges.begin()
    std::sort(begin(stooges), end(stooges),
              [](const Person &p1, const Person &p2) { return p1.get_name() < p2.get_name(); });

    // end(stooges) or stooges.end()
    std::for_each(begin(stooges), end(stooges),
                  [](const Person &p) { std::cout << p << std::endl; });

    std::cout << std::endl;

    std::sort(begin(stooges), end(stooges),
              [](const Person &p1, const Person &p2) { return p1.get_age() < p2.get_age(); });

    std::for_each(begin(stooges), end(stooges),
                  [](const Person &p) { std::cout << p << std::endl; });
}

int main()
{
    // test1();
    // test2();
    // test3();
    test4();
    // test5();
    // test6();
    // test7();

    std::cout << std::endl;
    return 0;
}
