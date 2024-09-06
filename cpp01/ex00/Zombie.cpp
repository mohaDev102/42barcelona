#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

Zombie* newZombie(std::string name)
{
   return new Zombie(name);
}

Zombie::~Zombie()
{
    std::cout << name << " has been destroyed." << std::endl;
}

void randomChump(std::string name)
{
    Zombie Zombie(name);
    Zombie.announce();
}

void Zombie::announce()
{
    std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}