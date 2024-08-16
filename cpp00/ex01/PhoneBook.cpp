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
    std::cout << std::setw(10) << std::right << "Index" << "|" 
    << std::setw(10) << std::right << "First Name" << "|" 
    << std::setw(10) << std::right << "Last Name" << "|"
    << std::setw(10) << std::right << "Nickname" << std::endl;
    for (int i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << std::right << i << "|"
        << std::setw(10) << std::right << truncateText(contacts[i].getFirstName()) << "|"
        << std::setw(10) << std::right << truncateText(contacts[i].getLastName()) << "|"
        << std::setw(10) << std::right << truncateText(contacts[i].getNickName()) << std::endl;
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

std::string PhoneBook::truncateText(const std::string& value)
{
    if (value.length() > 10)
        return value.substr(0, 9) + ".";
    else
        return value;
}
int PhoneBook::isPhoneNumberValid(std::string &phoneNumber)
{
    if (phoneNumber.length() == 9)
        return (0);
    return (1);
}

