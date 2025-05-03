#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException() {}

const char *Form::GradeTooHighException::what() const throw() {
    return "Form exception: grade is too high";
}

Form::GradeTooLowException::GradeTooLowException() {}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form exception: grade is too low";
}

Form::Form() : _name("default"), _isSigned(false),
    _signGrade(MIN_GRADE), _executeGrade(MIN_GRADE) {}

Form::Form(const std::string& name, int signGrade, int executeGrade) : _name(name),
_signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < MAX_GRADE || executeGrade < MAX_GRADE)
        throw Form::GradeTooHighException();
    if (signGrade > MIN_GRADE || executeGrade > MIN_GRADE)
        throw Form::GradeTooLowException();
    this->_isSigned = false;
}

Form::Form(const Form& other) : _name(other.getName()),
_isSigned(other.getIsSigned()), _signGrade(other.getSignGrade()),
_executeGrade(other.getExecuteGrade()) {
    if (this->_signGrade < MAX_GRADE || this->_executeGrade < MAX_GRADE)
        throw Form::GradeTooHighException();
    if (this->_signGrade > MIN_GRADE || this->_executeGrade > MIN_GRADE)
        throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form& other) {
    (void) other;
    return *this;
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->_signGrade)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

const std::string& Form::getName() const { return this->_name; }

bool Form::getIsSigned() const { return this->_isSigned; }

int Form::getSignGrade() const { return this->_signGrade; }

int Form::getExecuteGrade() const { return this->_executeGrade; }

std::ostream&  operator<<(std::ostream& os, const Form& obj) {
    os << "Format " << obj.getName() << " signed: " << obj.getIsSigned()
    << ", signGrade: " << obj.getSignGrade() << ", executeGrade: " 
    << obj.getExecuteGrade();
    return os; 
}