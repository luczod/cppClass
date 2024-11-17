#include <algorithm>
#include <iostream>
#include <vector>

int global_x{ 1000 };

// Capture by value
// The global variable global_x cannot be captured because it is not
// within the reaching scope of the lambda. It can however still be accessed
// from within the lambda using normal name lookup rules.
void test1()
{
    std::cout << "\n---Test1 --------------------------" << std::endl;

    int local_x{ 100 };

    auto lambda1 = [local_x]() { // copy and const
        std::cout << local_x << std::endl;
        std::cout << global_x << std::endl;
    };

    lambda1();
}

// Capture by value - mutable
// The captured variable x can only be modified within the lambda by
// using the mutable keyword. Note that this modifiability only pertains to
// the captured variable within the lambda body and not the actual variable.
void test2()
{
    std::cout << "\n---Test2 --------------------------" << std::endl;

    int x{ 100 };

    auto lambda2 = [x]() mutable { // copy and mutable
        x += 100;
        std::cout << x << std::endl;
    };

    lambda2(); // 200
    std::cout << x << std::endl;

    // It does not capture the variable again,
    // since the object(lambda2) has already been instantiated/initialized.
    lambda2(); // 300
    std::cout << x << std::endl;
}

// Capture by reference
// Any changes made to the captured reference variable within the lambda body
// will change the actual variable.
void test3()
{
    std::cout << "\n---Test3 --------------------------" << std::endl;

    int x{ 100 };

    auto lambda3 = [&x]() mutable { // No copy and mutable
        x += 100;
        std::cout << x << std::endl;
    };

    lambda3();
    std::cout << x << std::endl;
}

// Default capture by value - mutable
// Only variables used within the lambda body are captured by value.
// The variable z is not captured by the lambda.
void test4()
{
    std::cout << "\n---Test4 --------------------------" << std::endl;
    int x{ 100 };
    int y{ 200 };
    // Note that z is not captured in the lambda since it is not used.
    // This should produce an 'unused variable' warning when compiling.
    // int z{ 300 };

    auto lambda4 = [=]() mutable { // copy and mutable, [=]
        x += 100;                  // capture x
        y += 100;                  // capture y
        std::cout << x << std::endl;
        std::cout << y << std::endl;
    };
    lambda4();

    std::cout << "\n";
    std::cout << x << std::endl;
    std::cout << y << std::endl;
}

// Default capture by reference
// This time because all three variables - x,y,z are used within
// the lambda body, all three of them will be captured by reference.
void test5()
{
    std::cout << "\n---Test5 --------------------------" << std::endl;

    int x{ 100 };
    int y{ 200 };
    int z{ 300 };

    auto lambda5 = [&]() { // No copy(reference) and mutable, [&]
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    lambda5();

    std::cout << "\n";
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Default capture by value, capture y by reference
void test6()
{
    std::cout << "\n---Test6 --------------------------" << std::endl;

    int x{ 100 };
    int y{ 200 };
    int z{ 300 };

    auto lambda6 = [=, &y]() mutable { // copy, No copy(reference) and mutable, [=, &y]
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    lambda6();

    std::cout << "\n";
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Default capture by reference, capture x and z by value
// Equivalent to test6
void test7()
{
    std::cout << "\n---Test7 --------------------------" << std::endl;

    int x{ 100 };
    int y{ 200 };
    int z{ 300 };

    auto lambda7 = [&, x, z]() mutable { // No copy(reference), copy, copy and mutable, [&, x, z]
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    lambda7();

    std::cout << "\n";
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Used for test8
class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);

private:
    std::string name;
    int age;

public:
    Person() = default;
    // Oveloded constructor
    Person(std::string name, int age)
        : name{ name }
        , age{ age } {};

    // copy and const
    Person(const Person &p) = default;

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
    // [this],[=],[&] all capture by reference
    auto change_person1()
    {
        return [this](std::string new_name, int new_age) {
            name = new_name;
            age = new_age;
        };
    }
    auto change_person2()
    {
        return [=](std::string new_name, int new_age) {
            name = new_name;
            age = new_age;
        };
    }
    auto change_person3()
    {
        return [&](std::string new_name, int new_age) {
            name = new_name;
            age = new_age;
        };
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << "[Person, " << p.name << " : " << p.age << "]";
    return os;
}

// Default capture by reference of the current object using [this]
// [=], [&], and [this] are equivalent when capturing an object's member variables - all are
// captured by reference Notre that capturing this with [=] has been deprecated in C++20 Also, C++20
// allows [*this], which captures by value!
void test8()
{
    std::cout << "\n---Test8 --------------------------" << std::endl;

    Person person("Larry", 18);
    std::cout << person << std::endl;

    // Default capture [this]
    // This is the preferred way
    auto change_person1 = person.change_person1();
    change_person1("Moe", 30);
    std::cout << person << std::endl;

    // Default capture [=]
    // This has been deprecated in C++20
    auto change_person2 = person.change_person2();
    change_person2("Curly", 25);
    std::cout << person << std::endl;

    // Default capture [&]
    auto change_person3 = person.change_person3();
    change_person3("Frank", 34);
    std::cout << person << std::endl;
}

// Used for test9
// class or struct
class Lambda
{
private:
    int y;

public:
    Lambda(int y)
        : y{ y } {};

    // Overloding operator "()"
    void operator()(int x) const
    {
        std::cout << x + y << std::endl;
    };
};

// Variable lambda2 is equivalent to class Lambda
void test9()
{
    std::cout << "\n---Test9 --------------------------" << std::endl;

    int y{ 100 };

    Lambda lambda1(y); // object
    auto lambda2 = [y](int x) { std::cout << x + y << std::endl; };

    lambda1(200);
    lambda2(200);
}

// Class used in the test10() example
class People
{
    std::vector<Person> people;
    int max_people;

public:
    People(int max = 10)
        : max_people(max) {};
    // copy constructor
    People(const People &p) = default;

    void add(std::string name, int age)
    {
        people.emplace_back(name, age);
    }

    void set_max_people(int max)
    {
        max_people = max;
    }

    int get_max_people() const
    {
        return max_people;
    }

    void display_people(std::vector<Person> people)
    {
        std::cout << "\n" << std::endl; // white line
        for(const auto &p : people) {
            std::cout << p << std::endl;
        }

        return;
    }

    // This method returns a vector of Person objects in
    // people whose age > max_age AND it limits the number of
    // persons returned to be <= max_people the member variable max_people.
    // Note that the lambda in this example captures this, by reference, and by value
    std::vector<Person> get_people(int max_age)
    {
        std::vector<Person> result;
        int count{ 0 }; // &count

        std::copy_if(people.begin(), people.end(), std::back_inserter(result),
                     [this, &count, max_age](const Person &p) { // p comes from copy_if
                         return p.get_age() > max_age && ++count <= max_people; // this->max_people
                     });

        display_people(result);

        return result;
    }
};

void test10()
{
    std::cout << "\n---Test10 --------------------------" << std::endl;
    People friends;

    friends.add("Larry", 18);
    friends.add("Curly", 25);
    friends.add("Moe", 35);
    friends.add("Frank", 28);
    friends.add("James", 65);

    auto result = friends.get_people(17);

    //    std::cout << std::endl;
    //    for(const auto &p : result) {
    //        std::cout << p << std::endl;
    //    }

    friends.set_max_people(3);

    result = friends.get_people(17);

    result = friends.get_people(50);
}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    // test8();
    // test9();
    test10();

    std::cout << "\n";
    return 0;
}