
#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

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
            Contact newContact;

            std::string input;

            std::cout << "Enter First Name: ";
            std::getline(std::cin, input);
            newContact.setFirstName(input);
            std::cout << "Enter Last Name: ";
            std::getline(std::cin, input);
            newContact.setLastName(input);
            std::cout << "Enter Nick Name: ";
            std::getline(std::cin, input);
            newContact.setNickName(input);
            std::cout << "Enter Phone Number: ";
            std::getline(std::cin, input);
            newContact.setPhoneNumber(input);
            std::cout << "Enter Darkest Secret: ";
            std::getline(std::cin, input);
            newContact.setDarkestSecret(input);
            phoneBook.addContact(newContact);
        }
        else if (arg == "SEARCH")
        {
            phoneBook.displayContacts();
            std::cout << "Enter the index of the contact to view details:";
            std::getline(std::cin, arg);
            int index = atoi(arg.c_str());
            phoneBook.displayContactDetails(index);
        }
        else if (arg == "EXIT")
        {
            return (0);
        }
        else if (!std::getline(std::cin, arg)) 
        {
            if (std::cin.eof()) {
                std::cout << "\nEnd of input detected. Exiting..." << std::endl;
                break;
            }
            std::cin.clear();
            std::cout << "Invalid input. Please try again." << std::endl;
            continue;
        }
        else
            std::cout << "Invalid argument, Seleccione una de las opciones en pantalla" << std::endl;
        
    }
}