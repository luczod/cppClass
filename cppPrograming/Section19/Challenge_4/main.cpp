// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <fstream>
#include <iomanip>
#include <iostream>

void all_lines(std::ifstream &in_file, std::ofstream &out_file)
{
    std::string line{};
    int line_number{ 0 };

    while(std::getline(in_file, line)) {
        ++line_number;
        out_file << std::setw(7) << std::left << line_number << line << std::endl;
    }

    std::cout << "File copied and enumerated" << std::endl;
    in_file.close();
    out_file.close();
}

void no_white_lines(std::ifstream &in_file, std::ofstream &out_file)
{
    std::string line{};
    int line_number{ 0 };

    while(std::getline(in_file, line)) {
        if(line == "") {
            out_file << std::endl;
        } else {
            ++line_number;
            out_file << std::setw(7) << std::left << line_number << line << std::endl;
        }
    }

    std::cout << "File copied and enumerated" << std::endl;
}

int main()
{

    std::ifstream in_file{ "./romeoandjuliet.txt" };
    std::ofstream out_file{ "./romeoandjuliet_out.txt" };

    if(!in_file) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }

    if(!out_file) {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }

    // all_lines(in_file, out_file);
    no_white_lines(in_file, out_file);

    return 0;
}
