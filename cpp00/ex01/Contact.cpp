#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void Contact::setFirstName(const std::string &name) {FirstName = name;}


std::string Contact::getFirstName() const {return FirstName;}
