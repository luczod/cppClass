// Section 20
// Challenge 3
// Maps and Sets

#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

// Used for Part1
// Display the word and count from the
// std::map<std::string, int>

void display_words(const std::map<std::string, int> &words)
{
    std::cout << std::setw(12) << std::left << "\nWord" << std::setw(7) << std::right << "Count"
              << std::endl;
    std::cout << "===================" << std::endl;
    for(auto pair : words) {
        std::cout << std::setw(12) << std::left << pair.first << std::setw(7) << std::right
                  << pair.second << std::endl;
    }
}

// Used for Part2
// Display the word and occurences from the
// std::map<std::string, std::set<int>>

void display_words(const std::map<std::string, std::set<int>> &words)
{
    std::cout << std::setw(12) << std::left << "\nWord"
              << "Occurrences" << std::endl;
    std::cout << "====================================================================="
              << std::endl;
    for(auto pair : words) {
        std::cout << std::setw(12) << std::left << pair.first << std::left << "[ ";
        for(auto i : pair.second) {
            std::cout << i << " ";
        }
        std::cout << "]" << std::endl;
    }
}

// This function removes periods, commas, semicolons and colon in
// a string and returns the clean version
std::string clean_string(const std::string &s)
{
    std::string result;
    for(char c : s) {
        if(c == '.' || c == ',' || c == ';' || c == ':') {
            continue;
        } else {

            result += c;
        }
    }
    return result;
}

// Part1 process the file and builds a map of words and the
// number of times they occur in the file

void part1()
{
    std::map<std::string, int> words;
    std::string line;
    std::string word;
    std::ifstream in_file{ "./words.txt" };
    if(!in_file) {
        std::cerr << "Error opening input file" << std::endl;
        return;
    }

    while(in_file >> line) {
        line = clean_string(line);

        if(words.count(line)) {
            words[line] += 1;
        } else {
            words.insert(std::pair<std::string, int>(line, 1));
        }
        // std::cout << line << "\n" << std::endl;
    }

    in_file.close();
    display_words(words);
}

void part1_solution()
{
    std::map<std::string, int> words;
    std::string line;
    std::string word;
    std::ifstream in_file{ "../words.txt" };
    if(in_file) {
        while(std::getline(in_file, line)) {
            // std::cout << line;
            std::stringstream ss(line);
            while(ss >> word) {
                word = clean_string(word);
                words[word]++; // increment the count for the word in the map
            }
        }
        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}

// Part2 process the file and builds a map of words and a
// set of line numbers in which the word appears
void part2()
{
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    // int line_number{ 0 };
    std::ifstream in_file{ "./words.txt" };
    if(!in_file) {
        std::cerr << "Error opening input file" << std::endl;
        return;
    }

    while(std::getline(in_file, line)) {
        int line_number{ 0 };
        ++line_number;
        // line = clean_string(line);
        std::istringstream str_stream{ line };
        while(str_stream >> word) {
            word = clean_string(word);
            words[word].insert(line_number);
        }

        /*while(str_stream >> word) {
            // std::cout << word << " - " << line_number << std::endl;
            auto it = words.find(word);
            if(it != words.end()) {
                it->second.insert(line_number);
            } else {
                words.insert(std::pair<std::string, std::set<int>>(word, { line_number }));
            }
        }*/
    }

    in_file.close();
    display_words(words);
}

void part2_solution()
{
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    std::ifstream in_file{ "../words.txt" };
    if(in_file) {
        int line_number = 0;
        while(std::getline(in_file, line)) {
            // std::cout << line;
            line_number++;
            std::stringstream ss(line);
            while(ss >> word) {
                word = clean_string(word);
                words[word].insert(line_number);
            }
        }
        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}

int main()
{
    // part1();
    part2();
    return 0;
}
