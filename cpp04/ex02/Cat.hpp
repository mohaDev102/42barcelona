#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
{
    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();
        void makeSound() const;
        Brain *getBrain() const;
    private:
        Brain* brain;
};

#endif