
#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook phoneBook;
    std::string arg;

    while (true)
    {
        std::cout << "Ingrese una Opcion (ADD, SEARCH, EXIT)";
        std::getline(std::cin, arg);

        if (arg == "ADD")
        {
            
        }
        else if (arg == "SEARCH")
        {
            phoneBook.displayContacts();
        }
        else if (arg == "EXIT")
        {
            return (0); // o break?
        }
        else
            std::cout << "Invalid argument, Seleccione una de las opciones en pantalla" << std::endl;
        
    }
}