
#include "Bureaucrat.hpp"

int main()
{
     std::cout << "Test 1" << std::endl;

    std::cout << "Creating 'bureaucrat'" << std::endl;
    Bureaucrat bureaucrat("Bureaucrat", 150);
    std::cout << bureaucrat << std::endl;

    std::cout << "Trying to decrement 'bureaucrat' grade" << std::endl;
    try {
        bureaucrat.decrementGrade();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << bureaucrat << std::endl;
    std::cout << std::endl;
    std::cout << "=========================================================" << std::endl;

    std::cout << "Test 2" << std::endl;
    
    std::cout << "Creating 'Jhon'" << std::endl;
    Bureaucrat jhon("Jhon", 1);

    std::cout << jhon << std::endl;
    std::cout << "Trying to increment Jhon grade" << std::endl;
    try {
        jhon.incrementGrade();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << jhon << std::endl;
    std::cout << std::endl;
    std::cout << "=========================================================" << std::endl;

    std::cout << "Test 3" << std::endl;

    std::cout << "Trying to create a bureaucrat with negative grade" << std::endl;
    try {
        Bureaucrat gian("Gian", -253);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Trying to create a bureaucrat with grade too small" << std::endl;
    try {
        Bureaucrat gian("Gian", 168);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=========================================================" << std::endl;

    std::cout << "Test 4" << std::endl;

    std::cout << "Creating 'Laura'" << std::endl;
    Bureaucrat laura("Laura", 1);

    std::cout << "Looping over valid range" << std::endl;
    try {
        for (int i = 1; i < 150; i++) {
            laura.decrementGrade();
        }
        for (int i = 1; i < 150; i++) {
            laura.incrementGrade();
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << laura << std::endl;
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