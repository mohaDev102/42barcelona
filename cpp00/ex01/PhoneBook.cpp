#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : index(0), contactCount(0) {}

void PhoneBook::addContact(Contact &contact)
{
    contacts[index] = contact;
    index = (index + 1) % 8;
    if (contactCount < 8)
        contactCount++;
}

void PhoneBook::displayContacts()
{
    std::cout << "Index" << "|" << "First Name" << "|"  << "Last Name" \
    << "|" << "Nickname" << std::endl;
    for (int i = 0; i < contactCount; i++)
    {
        std::cout << "|" << i << "|" << contacts[i].getFirstName() << contacts[i].getLastName() << contacts[i].getNickName() << std::endl;
    }
}

void PhoneBook::displayContactDetails(int index)
{
    if (index < 0 || index >= contactCount)
    {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}