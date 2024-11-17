// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <algorithm>
#include <cctype>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// template function to display any deque
template <typename T>
void display(const std::deque<T> &d)
{
    std::cout << "[";
    for(const auto &elem : d) {
        std::cout << elem << ", ";
    }
    std::cout << "]" << std::endl;
}

bool is_palindrome(const std::string &s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    // if(seq.size() % 2 == 0){}
    // if(line == "") { out_file << std::endl; }
    if(s.length() == 1) {
        return true;
    }
    std::string txt{ s };
    std::transform(txt.begin(), txt.end(), txt.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    std::deque<char> seq;
    std::deque<char> rseq;

    std::copy(txt.begin(), txt.end(), std::front_inserter(seq));
    std::copy(txt.begin(), txt.end(), std::back_inserter(rseq));
    // Using the erase, remove_if, and ::isspace functions.
    seq.erase(std::remove_if(seq.begin(), seq.end(),
                             [](auto const &c) -> bool { return !std::isalnum(c); }),
              seq.end());
    rseq.erase(std::remove_if(rseq.begin(), rseq.end(),
                              [](auto const &c) -> bool { return !std::isalnum(c); }),
               rseq.end());

    //    display(seq);
    //    display(rseq);

    if(seq == rseq) {
        return true;
    }
    return false;
}

bool palindrome_solution(const std::string &s)
{
    std::deque<char> d;

    // add all the string characters that are alpha to the back of the deque in uppercase
    for(char c : s) {
        if(std::isalpha(c)) {
            d.push_back(std::toupper(c));
        }
    }
    char c1{};
    char c2{};
    // while are more than 1 characters in the deque
    //      remove and compare the front character with the back character
    //      if they are not the same - return false since it can't be a palindrome
    // if you complete the loop then the string must be a palindrome so return true
    while(d.size() > 1) {
        c1 = d.front();
        c2 = d.back();
        d.pop_front();
        d.pop_back();
        if(c1 != c2) {
            return false;
        }
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
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal Panama!",
        "This is a palindrome",
        "palindrome"
    };

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;

    for(const auto &s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    // is_palindrome("A Toyota's a toyota");
    std::cout << std::endl;
    return 0;
}