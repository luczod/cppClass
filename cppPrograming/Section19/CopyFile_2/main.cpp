// Section 19
// Copy File 2
// File copy using get/put
#include <fstream>
#include <iostream>
// #include <string>

int main()
{
    std::ifstream in_file{ "poem.txt" };
    std::ofstream out_file{ "poem_out.txt" };

    if(!in_file) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }

    if(!out_file) {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }

    char c;
    while(in_file.get(c)) {
        out_file.put(c); // writes a single character to a text file.
    }

    std::cout << "File copied" << std::endl;
    in_file.close();
    out_file.close();
    return 0;
}
