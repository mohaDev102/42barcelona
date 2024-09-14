#include <iostream>
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
class ClapTrap
{
    private:
        std::string name;
        unsigned int hitPoint;
        unsigned int energyPoints;
        unsigned int attackDamage;
    public:
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &other);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& other);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif