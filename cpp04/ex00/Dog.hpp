#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog()
        {
            type = "Dog";
            std::cout << "Dog constructor called" << std::endl;
        }
        ~Dog()
        {
            std::cout << "Dog destructor called" << std::endl;
        }
        void makeSound() const
        {
            std::cout << "Woof Woof" << std::endl;
        }
};

#endif