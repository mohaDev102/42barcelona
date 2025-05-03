#ifndef Base_HPP
#define Base_HPP

#include <iostream>

class Base
{
    public:
        virtual ~Base() {}
};
Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif