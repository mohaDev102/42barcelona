#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class Intern
{
    public:
        Intern();
        Intern(const Intern &src);
        ~Intern();
        Intern &operator=(const Intern &src);
        AForm *makeForm(std::string formName, std::string target);
};

#endif