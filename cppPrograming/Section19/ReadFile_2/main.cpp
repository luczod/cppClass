// Section 19
// Read File 2
// Continuous read of 3 data items in a loop
#include <fstream>
#include <iomanip>
#include <iostream>

int main()
{
    std::ifstream in_file;
    std::string line;
    int num;
    double total;

    in_file.open("./test.txt");

    if(!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    //    while(!in_file.eof()){ win
    while(in_file >> line >> num >> total) {
        std::cout << std::setw(10) << std::left << line << std::setw(10) << num << std::setw(10)
                  << total << std::endl;
    }
    in_file.close(); // important
    return 0;
}
