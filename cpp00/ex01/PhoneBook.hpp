#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

private:
    Contact contacts[8];
    int index;
    int contactCount;

public:
    PhoneBook();
    void addContact(Contact &contact);
    void displayContacts();
    void displayContactDetails(int index);
    std::string truncateText(const std::string& value);
    int isPhoneNumberValid(std::string &phoneNumber);

};

#endif