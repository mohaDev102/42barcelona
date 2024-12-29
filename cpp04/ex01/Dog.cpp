#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this == &other)
        return *this;
    this->type = other.getType();
    this->brain = new Brain(*other.brain);
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete (this->brain);
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}

Brain *Dog::getBrain() const
{
    return (this->brain);
}