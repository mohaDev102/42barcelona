#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
    if (n <= 0)
        return (NULL);
    Zombie* horde = new Zombie[n];
    for (int i = 1; i < n; i++)
    {
        horde[i] = Zombie(name);
    }
    return (horde);
}