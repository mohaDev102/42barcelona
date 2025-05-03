#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


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

    std::cout << "Creating bureaucrat " << name << " with grade " 
    << grade << std::endl;
    try {
        bureaucrat = new Bureaucrat(name, grade);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    std::cout << "Creating " << type << " format with " << target 
    << " target" << std::endl;
    form = createAForm(type, target);
    if (!form) {
        std::cout << "Invalid form type" << std::endl;
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
    std::cout << "Test 1: Not enough grade to sign shrubbery format" << std::endl;
    std::cout << std::endl;
    signExecuteTest("shrubbery", "home", "jhon", 147);
    

    std::cout << "Test 2: Not enough grade to execute shrubbery format" << std::endl;
    std::cout << std::endl;
    signExecuteTest("shrubbery", "home", "peter", 142);
    

    std::cout << "Test 3: Enough grade for shrubbery format" << std::endl;
    std::cout << std::endl;
    signExecuteTest("shrubbery", "correct", "gwen", 130);
    

    std::cout << "Test 4: Not enough grade to sign robotomy format" << std::endl;
    std::cout << std::endl;
    signExecuteTest("robotomy", "alex", "jhon", 75);
    

    std::cout << "Test 5: Not enough grade to execute robotomy format" << std::endl;
    std::cout << std::endl;
    signExecuteTest("robotomy", "alex", "peter", 48);

    return 0;
}