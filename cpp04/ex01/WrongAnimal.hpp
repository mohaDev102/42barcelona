#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal();
    virtual ~WrongAnimal();
    void makeSound() const;
    std::string getType() const;
};

#endif