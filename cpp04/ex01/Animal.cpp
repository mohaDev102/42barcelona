
#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Some generic animal sound" << std::endl;
}

std::string const &Animal::getType() const
{
    return type;
}