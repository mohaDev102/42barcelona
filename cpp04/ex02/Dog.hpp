#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();
        void makeSound() const;
        Brain *getBrain() const;
    private:
        Brain* brain;
};

#endif