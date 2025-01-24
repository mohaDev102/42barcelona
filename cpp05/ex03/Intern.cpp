
#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern: " << "Default constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
    *this = src;
}

Intern::~Intern()
{
    std::cout << "Intern: " << "Destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
    (void)src;
    return *this;
}

Form* Intern::makeForm(std::string formName, std::string target)
{
    try
    {
        std::cout << "Intern creates" << formName << std::endl;
    }
    catch (std::exception &e)
    {
       std::cout << "Intern cannot create" << formName << std::endl;
    }

}