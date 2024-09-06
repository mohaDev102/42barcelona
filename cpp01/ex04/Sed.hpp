#ifndef SED_HPP
#define SED_HPP

#include <string>

class Sed {
public:
    Sed(const std::string &filename, const std::string &s1, const std::string &s2);
    void replaceInFile() const;

private:
    std::string filename;
    std::string s1;
    std::string s2;
    std::string replaceAll(const std::string& line) const;
};

#endif