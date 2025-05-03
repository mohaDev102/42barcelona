#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::GradeTooHighException::GradeTooHighException() {}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Form exception: grade is too high";
}

AForm::GradeTooLowException::GradeTooLowException() {}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Form exception: grade is too low";
}

AForm::FormNotSignedException::FormNotSignedException() {}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form exception: format is not signed";
}

AForm::AForm() : name("default"), isSigned(false),
    signGrade(MIN_GRADE), executeGrade(MIN_GRADE) {}

AForm::AForm(const std::string& name, int signGrade, int executeGrade) : name(name),
signGrade(signGrade), executeGrade(executeGrade) {
    if (signGrade < MAX_GRADE || executeGrade < MAX_GRADE)
        throw AForm::GradeTooHighException();
    if (signGrade > MIN_GRADE || executeGrade > MIN_GRADE)
        throw AForm::GradeTooLowException();
    this->isSigned = false;
}

AForm::AForm(const AForm& other) : name(other.getName()),
isSigned(other.getIsSigned()), signGrade(other.getSignGrade()),
executeGrade(other.getExecuteGrade()) {
    if (this->signGrade < MAX_GRADE || this->executeGrade < MAX_GRADE)
        throw AForm::GradeTooHighException();
    if (this->signGrade > MIN_GRADE || this->executeGrade > MIN_GRADE)
        throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other) {
    (void) other;
    return *this;
}

AForm::~AForm() {}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->signGrade)
        throw AForm::GradeTooLowException();
    this->isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!this->isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->executeGrade)
        throw AForm::GradeTooLowException();
    action();
}

const std::string& AForm::getName() const { return this->name; }

bool AForm::getIsSigned() const { return this->isSigned; }

int AForm::getSignGrade() const { return this->signGrade; }

int AForm::getExecuteGrade() const { return this->executeGrade; }

std::ostream&  operator<<(std::ostream& os, const AForm& obj) {
    os << "AFormat " << obj.getName() << " signed: " << obj.getIsSigned()
    << ", signGrade: " << obj.getSignGrade() << ", executeGrade: " 
    << obj.getExecuteGrade();
    return os; 
}