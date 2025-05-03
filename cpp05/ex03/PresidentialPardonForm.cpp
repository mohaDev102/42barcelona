#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
AForm("presidential pardon", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
AForm("presidential pardon", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()),
target(other.getTarget()) {}


PresidentialPardonForm::~PresidentialPardonForm() {}


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    (void) other;
    return *this;
}

void PresidentialPardonForm::action() const {
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const std::string& PresidentialPardonForm::getTarget() const { return this->target; }