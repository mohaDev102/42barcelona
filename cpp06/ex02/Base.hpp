#ifndef Base_HPP
#define Base_HPP
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

class Base
{
    public:
        virtual ~Base() {}
        Base* generate(void);
        void identify(Base* p);
        void identify(Base& p);
};

#endif