#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

    std::cout << "Test 1" << std::endl;
    std::cout << std::endl;

    std::cout << "Creating format 'Format' with valid parameters" << std::endl;
    Form format("Format", 5, 20);
    std::cout << format << std::endl;

    std::cout << "Creating formats with invalid parameters" << std::endl;

    try {
        Form format("Format", 155, 20);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form format("Format", -3, 20);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "=========================================================" << std::endl;

    std::cout << "Test 2" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Creating bureaucrat 'Jhon' with not enough grade" << std::endl;
    Bureaucrat jhon("Jhon", 7);
    std::cout << jhon << std::endl;

    std::cout << "Creating bureaucrat 'Gian' with not enough grade" << std::endl;
    Bureaucrat gian("Gian", 8);
    std::cout << gian << std::endl;

    std::cout << "Jhon trying to sign format" << std::endl;
    jhon.signForm(format);

    std::cout << "Gian trying to sign format" << std::endl;
    gian.signForm(format);

    std::cout << format << std::endl;
    std::cout << std::endl;
    std::cout << "=========================================================" << std::endl;

    std::cout << "Test 3" << std::endl;
    std::cout << std::endl;

    std::cout << "Creating format 'Format2' with valid parameters" << std::endl;
    Form format2("Format2", 5, 20);
    std::cout << format2 << std::endl;

    std::cout << "Creating bureaucrat 'Maria' with enough grade" << std::endl;
    Bureaucrat maria("Maria", 3);
    std::cout << maria << std::endl;

    std::cout << "Maria trying to sign Format2" << std::endl;
    maria.signForm(format2);

    std::cout << format2 << std::endl;
    std::cout << std::endl;
}