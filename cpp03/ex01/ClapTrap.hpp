#include <iostream>
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
class ClapTrap
{
    protected:
        std::string name;
        unsigned int hitPoint;
        unsigned int energyPoints;
        unsigned int attackDamage;
    public:
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &other);
        virtual ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& other);
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif