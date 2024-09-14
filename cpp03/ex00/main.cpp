#include "ClapTrap.hpp"

int main() {
    // Crear un ClapTrap
    ClapTrap claptrap1("Clappy");

    // Realizar ataques
    claptrap1.attack("Target1");
    claptrap1.takeDamage(3);
    claptrap1.beRepaired(2);

    // Segundo ataque
    claptrap1.attack("Target2");
    claptrap1.takeDamage(5);
    claptrap1.beRepaired(4);

    // Sin energía ni puntos de vida
    claptrap1.takeDamage(10);
    claptrap1.attack("Target3");
    claptrap1.beRepaired(5);

    return 0;
}