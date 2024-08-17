
#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
    PhoneBook phoneBook;
    std::string arg;

    while (true)
    {
        std::cout << "Insert an Option (ADD, SEARCH, EXIT)";
        std::getline(std::cin, arg);

        if (arg == "ADD")
        {
            Contact newContact;
            std::string input;

			std::cout << "Enter First Name: ";
            std::getline(std::cin, input);
            while (input.empty()) {
                if (std::cin.eof()) {
                    std::cout << "\nExiting" << std::endl;
                    return (0);
                }
                std::cout << "First Name cannot be empty. Please enter again: ";
                std::getline(std::cin, input);
            }
            newContact.setFirstName(input);


            std::cout << "Enter Last Name: ";
            std::getline(std::cin, input);
            while (input.empty()) {
                if (std::cin.eof()) {
                    std::cout << "\nExiting" << std::endl;
                    return (0);
                }
                std::cout << "Last Name cannot be empty. Please enter again: ";
                std::getline(std::cin, input);
            }
            newContact.setLastName(input);


            std::cout << "Enter Nick Name: ";
            std::getline(std::cin, input);
            while (input.empty()) {
                if (std::cin.eof()) {
                    std::cout << "\nExiting" << std::endl;
                    return (0);
                }
                std::cout << "Nick Name cannot be empty. Please enter again: ";
                std::getline(std::cin, input);
            }
            newContact.setNickName(input);


            std::cout << "Enter Phone Number: ";
            std::getline(std::cin, input);
            while (input.empty() || phoneBook.isPhoneNumberValid(input)) {
                if (std::cin.eof()) {
                    std::cout << "\nExiting" << std::endl;
                    return (0);
                }
                std::cout << "Invalid or empty Phone Number. Please enter again: ";
                std::getline(std::cin, input);
            }
            newContact.setPhoneNumber(input);


            std::cout << "Enter Darkest Secret: ";
            std::getline(std::cin, input);
            while (input.empty()) {
                if (std::cin.eof()) {
                    std::cout << "\nExiting" << std::endl;
                    return (0);
                }
                std::cout << "Darkest Secret cannot be empty. Please enter again: ";
                std::getline(std::cin, input);
            }
            newContact.setDarkestSecret(input);
            phoneBook.addContact(newContact);
        }
        else if (arg == "SEARCH")
        {
            phoneBook.displayContacts();
            while (1)
            {
                std::string input;
                std::cout << "Enter the index of the contact to view details:";
                if (std::getline(std::cin, input) && input.size()  != 1)
                {
                        break;
                }
                if (input.empty())
                {
                    std::cout << "No index entered.  Please enter a valid index." << std::endl;
                    continue;
                }
                int index = atoi(input.c_str());
                if (index >= 1 && index < 9)
                {
                    phoneBook.displayContactDetails(index -1);
                    break;
                }              
            }
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