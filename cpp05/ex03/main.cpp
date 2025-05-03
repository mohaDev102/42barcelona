#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

AForm *createAForm(std::string& type, std::string& target) {
    if (type == "shrubbery")
        return new ShrubberyCreationForm(target);
    if (type == "robotomy")
        return new RobotomyRequestForm(target);
    if (type == "presidential")
        return new PresidentialPardonForm(target);
    return NULL;
}

void signExecuteTest(std::string type, std::string target, std::string name, int grade) {
    AForm *form = NULL;
    Bureaucrat *bureaucrat = NULL;
    Intern intern;

    std::cout << "Creating bureaucrat " << name << " with grade " 
    << grade << std::endl;
    try
    {
        bureaucrat = new Bureaucrat(name, grade);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }

    std::cout << "Creating " << type << " format with " << target 
    << " target" << std::endl;
    form = intern.makeForm(type, target);
    if (!form)
    {
        delete bureaucrat;
        return;
    }

    std::cout << "Bureaucrat " << name << " attempting to sign and execute "
    << type << " format" << std::endl;
    bureaucrat->signAForm(*form);
    bureaucrat->executeForm(*form);
    delete form;
    delete bureaucrat;
}


int main()
{
    std::cout << "Test 1: Not existing form type" << std::endl;
    std::cout << std::endl;
    signExecuteTest("noneexisting", "home", "jhon", 130);
    

    std::cout << "Test 2: shrubbery creation form" << std::endl;
    std::cout << std::endl;
    signExecuteTest("shrubbery", "home", "peter", 130);
    

    std::cout << "Test 3: shrubbery request form" << std::endl;
    std::cout << std::endl;
    signExecuteTest("shrubbery", "correct", "gwen", 40);
    

    std::cout << "Test 4: robotomy pardon form" << std::endl;
    std::cout << std::endl;
    signExecuteTest("robotomy", "alex", "jhon", 3);

    return 0;
}