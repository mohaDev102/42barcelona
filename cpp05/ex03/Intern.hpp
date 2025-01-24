#ifndef INTERN_HPP
#define INTERN_HPP
#include "Form.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &src);
        ~Intern();
        Intern &operator=(const Intern &src);
        Form *makeForm(std::string formName, std::string target);
};

#endif