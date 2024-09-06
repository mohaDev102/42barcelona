
#include "Sed.hpp"
#include <fstream>
#include <iostream>

Sed::Sed(const std::string &filename, const std::string &s1, const std::string &s2)
    : filename(filename), s1(s1), s2(s2) {}

void Sed::replaceInFile() const {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file '" << filename << "' for reading." << std::endl;
        return;
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open the file '" << filename << ".replace' for writing." << std::endl;
        inputFile.close();
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << replaceAll(line) << std::endl;
    }

    inputFile.close();
    outputFile.close();
}

std::string Sed::replaceAll(const std::string& line) const {
    std::string result;
    std::size_t pos = 0, found;

    while ((found = line.find(s1, pos)) != std::string::npos) {
        result.append(line, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
    }

    result.append(line, pos);
    return result;
}