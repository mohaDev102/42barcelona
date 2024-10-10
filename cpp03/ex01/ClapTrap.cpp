#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoint(10),
    energyPoints(10), attackDamage(0) {
        std::cout << "ClapTrap " << name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoint(other.hitPoint),
    energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
        std::cout << "ClapTap " << other.name << " has been copied!" << std::endl; 
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoint = other.hitPoint;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << other.name << " has been assigned!" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (hitPoint == 0)
    {
        std::cout << "ClapTrap " << name << " has no hit points left and cannot attack!" << std::endl;
        return ;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy points left and cannot attack!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoint == 0)
    {
        std::cout << "ClapTrap " << name << " is already down!" << std::endl;
        return ;
    }
    hitPoint = (amount >= hitPoint) ? 0 : hitPoint - amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining hit points: " << hitPoint << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoint == 0)
    {
        std::cout << "ClapTrap " << name << " has no hit points and cannot be repaired!" << std::endl;
        return ;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy points left and cannot be repaired!" << std::endl;
        return ;
    }
    hitPoint += amount;
    energyPoints--;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points! Total hit points: " << hitPoint << std::endl;
}
