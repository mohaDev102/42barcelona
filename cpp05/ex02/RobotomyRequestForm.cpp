#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy", 72, 45),
target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
AForm("robotomy", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()),
target(other.getTarget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    (void) other;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const {
    srand(time(NULL));
    if (rand() % 2 == 0) {
        std::cout << "BzzzZZZZZZzzzzz..." << std::endl
                  << this->target << " has been robotomized successfully." << std::endl;
    }
    else 
        std::cout << this->target << " robotomy failed." << std::endl;
}

const std::string& RobotomyRequestForm::getTarget() const { return this->target; }