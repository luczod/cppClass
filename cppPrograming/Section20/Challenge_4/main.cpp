// Section 20
// Challenge 4
// Identifying palindrome strings using a stack and queue
#include <cctype>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

template <typename T>
void display_queue(std::queue<T> q)
{
    std::cout << "[ ";

    while(!q.empty()) {
        T elem = q.front();
        q.pop();
        std::cout << elem << ", ";
    }

    std::cout << "]" << std::endl;
}

void display_char(char c)
{
    std::cout << s << std::endl;
}

template <typename T>
void display_stack(std::stack<T> s)
{
    std::cout << "[ ";
    while(!s.empty()) {
        T elem = s.top();
        s.pop(); // use a copy, because is a destructive process
        std::cout << elem << ", ";
    }
    std::cout << "]" << std::endl;
}

bool is_palindrome(const std::string &s)
{
    if(s.length() == 1) {
        return true;
    }

    std::queue<char> q;
    std::stack<char> stk; // default Deque

    for(char c : s) {
        if(std::isalpha(c)) {
            q.push(std::toupper(c));
            stk.push(std::toupper(c));
        }
    }

    while(!q.empty()) {
        //  display_queue(q);
        //  display_char(q.front());
        //
        //  display_stack(sd);
        //  display_char(sd.top());

        if(q.front() != stk.top()) {
            return false;
        }

        q.pop();
        stk.pop();
    }
    return true;
}

bool is_palindrome_solution(const std::string &s)
{
    std::stack<char> stk;
    std::queue<char> q;

    // add all the string characters that are alpha to the back of the queue  in uppercase
    // push all the string characters that are alpha on the stack

    for(char c : s)
        if(std::isalpha(c)) {
            c = std::toupper(c);
            q.push(c);
            stk.push(c);
        }

    char c1{};
    char c2{};

    // while the queue is not empty
    //      compare and remove the character at the top of the stack
    //      and the chacterter at the front of the queue
    //      if they are not the same - return false since it can't be a palindrome
    // if you complete the loop then the string must be a palindrome so return true
    while(!q.empty()) {
        c1 = q.front();
        q.pop();
        c2 = stk.top();
        stk.pop();

        if(c1 != c2)
            return false;
    }
    return true;
}

int main()
{
    std::vector<std::string> test_strings{
        "a",
        "aa",
        "aba",
        "abba",
        "abbcbba",
        "ab",
        "abc",
        "radar",
        "bob",
        "ana",
        "avid diva",
        "Amore, Roma",
        "A Toyota's a toyota",
        "A Santa at NASA",
        "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!",
        "This is a palindrome",
        "palindrome"
    };

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;

    for(const auto &s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    // std::string s{ "radar" };
    // is_palindrome(s);
    // std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    std::cout << std::endl;

    return 0;
}