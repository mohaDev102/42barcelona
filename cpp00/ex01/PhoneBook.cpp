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
        std::cout << "|" << i << "|" << contacts[i].getFirstName() << std::endl;
    }
}

void PhoneBook::displayContactDetails()
{
    // parecido al de arriba solo con mas datos
}