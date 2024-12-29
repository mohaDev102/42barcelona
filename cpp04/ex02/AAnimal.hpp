#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();

    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif // AANIMAL_HPP