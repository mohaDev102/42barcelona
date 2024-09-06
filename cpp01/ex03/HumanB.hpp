#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
#include <string>

class HumanB {
    private:
        std::string name;
        Weapon* weapon;

    public:
        HumanB(const std::string& name) : name(name), weapon(0) {}
        void setWeapon(Weapon& weapon);
        void attack() const;
};

#endif