
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *bure;
    try {
        bure = new Bureaucrat("PEPE", -1);

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    if (bure)
    {
        std::cout << *bure << std::endl;
        delete bure;
    }
    // try {
    //     Bureaucrat b2("Bob", 151);
    //     // std::cout << b2 << std::endl;
    //     b2.decrementGrade(); // Should throw GradeTooLowException
    // } catch (std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    // }

    // try {
    //     Bureaucrat b3("Charlie", 151); // Should throw GradeTooLowException
    // } catch (std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    // }

    // try {
    //     Bureaucrat b4("Dave", 0); // Should throw GradeTooHighException
    // } catch (std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    // }

    return 0;
}