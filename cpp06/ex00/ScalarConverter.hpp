
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdlib>

# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
# define MIN_FLOAT std::numeric_limits<float>::min() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
# define MIN_DOUBLE std::numeric_limits<double>::min() //-1.79769e+308
# define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308

enum    e_type
{
    SPECIAL = 0,
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4,
    INVALID = -1
};

class ScalarConverter
{
    public:
        static void convert(const std::string &str);
    private:
        ScalarConverter() {}
        ~ScalarConverter() {}
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
};

e_type wichType(const std::string &str, int len);
void convertChar(const std::string &str, int len);
void convertInt(const std::string &str);
void convertFloat(const std::string &str);
void convertDouble(const std::string &str);
void printSpecial(const std::string &str);

#endif