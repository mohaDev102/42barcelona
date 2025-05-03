#include "Form.hpp"

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

AForm::AForm() : _name("default"), _isSigned(false),
    _signGrade(MIN_GRADE), _executeGrade(MIN_GRADE) {}

AForm::AForm(const std::string& name, int signGrade, int executeGrade) : _name(name),
_signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < MAX_GRADE || executeGrade < MAX_GRADE)
        throw AForm::GradeTooHighException();
    if (signGrade > MIN_GRADE || executeGrade > MIN_GRADE)
        throw AForm::GradeTooLowException();
    this->_isSigned = false;
}

AForm::AForm(const AForm& other) : _name(other.getName()),
_isSigned(other.getIsSigned()), _signGrade(other.getSignGrade()),
_executeGrade(other.getExecuteGrade()) {
    if (this->_signGrade < MAX_GRADE || this->_executeGrade < MAX_GRADE)
        throw AForm::GradeTooHighException();
    if (this->_signGrade > MIN_GRADE || this->_executeGrade > MIN_GRADE)
        throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other) {
    (void) other;
    return *this;
}

AForm::~AForm() {}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->_signGrade)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) {
    if (!this->_isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->_executeGrade)
        throw AForm::GradeTooLowException();
    action();
}

const std::string& AForm::getName() const { return this->_name; }

bool AForm::getIsSigned() const { return this->_isSigned; }

int AForm::getSignGrade() const { return this->_signGrade; }

int AForm::getExecuteGrade() const { return this->_executeGrade; }

std::ostream&  operator<<(std::ostream& os, const AForm& obj) {
    os << "Format " << obj.getName() << " signed: " << obj.getIsSigned()
    << ", signGrade: " << obj.getSignGrade() << ", executeGrade: " 
    << obj.getExecuteGrade();
    return os; 
}