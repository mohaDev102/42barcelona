#include <iostream>
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
    protected:
        std::string type;
    public:
         Animal();
        virtual ~Animal();
        virtual void makeSound() const;
        std::string const &getType() const;
};

#endif