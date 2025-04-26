
#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &str)
{
    int len = str.length();

    e_type type = wichType(str, len);
    switch(type)
    {
        case INVALID:
            std::cerr << "Invalid input" << std::endl;
            break;
        case CHAR:
            convertChar(str, len);
            break;
        case INT:
            convertInt(str);
            break;
        case FLOAT:
            convertFloat(str);
            break;
        case DOUBLE:
            convertDouble(str);
            break;
        case SPECIAL:
            printSpecial(str);
    }
}


void printSpecial(const std::string &str)
{
   	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void convertChar(const std::string &str, int len)
{
    char c = 0;
    
    if (len == 1)
        c = str[0];
    else
        c = str[1];
    std::cout << "char:";
    if (isprint(c))
    {
        std::cout  << " '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    }
}


void convertInt(const std::string &str)
{
    long i = std::atol(str.c_str());

    std::cout << "char:";
    if (i < 0 || i > 127)
        std::cout << "impossible" << std::endl;
    else
    {
        if (isprint(static_cast<int>(i)))
            std::cout << " '" << static_cast<char>(i) << "'" << std::endl;
        else
            std::cout << " Non displayable" << std::endl;
    }
    std::cout << "int: ";
    if (i > 2147483647 && i > -2147483648)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(i) << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void convertFloat(const std::string &str)
{
    float f = std::atof(str.c_str());
    bool tolerance = std::fabs(f - static_cast<int>(f)) < 0.0000000000001;

    std::cout << f << std::endl;
    std::cout << "char:";
    if (f < 0 || f > 127)
        std::cout << "impossible" << std::endl;
    else
    {
        if (isprint(f))
            std::cout << " '" << static_cast<char>(f) << "'" << std::endl;
        else
            std::cout << " Non displayable" << std::endl;
    }
    std::cout << "int: ";
    if (f > 2147483647.0f || f  < -2147483648.0f)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;
    std::cout << "float: ";
    if (f < MIN_FLOAT || f > MAX_FLOAT)
        std::cout << "impossible" << std::endl;
    else
        std::cout << f << (tolerance ? ".0f" : "f") << std::endl;
    std::cout << "double: " << static_cast<double>(f) << (tolerance ? ".0" : "") << std::endl;
}

void convertDouble(const std::string &str)
{
    double d = std::atof(str.c_str());
    bool tolerance = std::fabs(d - static_cast<int>(d)) < 0.0000000000001;

    std::cout << "char:";
    if (d < 0 || d < 127)
        std::cout << "impossible" << std::endl;
    else
    {
        if (isprint(d))
            std::cout << " '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << " Non displayable" << std::endl;
    }
    std::cout << "int: ";
    if (d > 2147483647.0 && d > -2147483648.0)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
    std::cout << "float: ";
    if (d < MIN_FLOAT || d > MAX_FLOAT)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<float>(d) << (tolerance ? ".0f" : "f") << std::endl;
    std::cout << "double:";
    if (d < MIN_DOUBLE || d > MAX_DOUBLE)
        std::cout << "impossible" << std::endl;
    else
        std::cout << d << (tolerance ? ".0" : "") << std::endl;
}

e_type wichType(const std::string &str, int len)
{
    if (len == 1 && !isdigit(str[0]))
        return CHAR;
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
        return SPECIAL;
    if (str.find_first_not_of("0123456789.-+f") != std::string::npos)
        return INVALID;
    if (str.find('.') != std::string::npos)
    {
        if (str.find('f') != std::string::npos)
            return FLOAT;
        else
            return DOUBLE;
    }
    else
        return INT;
}

