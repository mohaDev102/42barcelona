#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void Contact::setFirstName(const std::string &name) {FirstName = name;}
void Contact::setLastName(const std::string &lastName) {LastName = lastName;}
void Contact::setNickName(const std::string &nickName) {NickName = nickName;}
void Contact::setPhoneNumber(const std::string &phoneNumer) {PhoneNumber = phoneNumer;}
void Contact::setDarkestSecret(const std::string &darkestSecret) {DarkestSecret = darkestSecret;}

std::string Contact::getFirstName() const {return FirstName;}
std::string Contact::getLastName() const {return LastName;}
std::string Contact::getNickName() const {return NickName;}
std::string Contact::getPhoneNumber() const {return PhoneNumber;}
std::string Contact::getDarkestSecret() const {return DarkestSecret;}

