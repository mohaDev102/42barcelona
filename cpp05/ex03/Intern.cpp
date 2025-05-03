
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

AForm *Intern::makeForm(std::string formName, std::string target)
{

    const char *forms[3] = {"shrubbery", "robotomy", "presidential"};

    int i = 0;
    while (i < 3 && forms[i] != formName)
        i++;
    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << formName << " form" << std::endl;
        return new ShrubberyCreationForm(target);
        break;
    case 1:
        std::cout << "Intern creates " << formName << " form" << std::endl;
        return new RobotomyRequestForm(target);
        break;
    case 2:
        std::cout << "Intern creates " << formName << " form" << std::endl;
        return new PresidentialPardonForm(target);
        break;
    }
    return NULL;
}