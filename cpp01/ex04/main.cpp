#include "Sed.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement_string>" << std::endl;
        return 1;
    }

    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: The string to be replaced (s1) is empty." << std::endl;
        return 1;
    }

    Sed replacer(filename, s1, s2);
    replacer.replaceInFile();

    return 0;
}