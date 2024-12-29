#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this == &other)
        return *this;
    this->type = other.getType();
    this->brain = new Brain(*other.brain);
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete (this->brain);
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}

Brain *Cat::getBrain() const
{
    return (this->brain);
}