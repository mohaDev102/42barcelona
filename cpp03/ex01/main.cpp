#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavTrap("SC4V-TP");
    scavTrap.attack("target");
    scavTrap.guardGate();
    return 0;
}