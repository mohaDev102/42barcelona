#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat()
        {
            type = "Cat";
            std::cout << "Cat constructor called" << std::endl;
        }
        ~Cat()
        {
            std::cout << "Cat destructor called" << std::endl;
        }
        void makeSound() const
        {
            std::cout << "Meow Meow" << std::endl;
        }
};

#endif