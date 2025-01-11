#include "Form.hpp"

Form::Form() : _name("default"), _signGrade(150), _execGrade(150)
{
    std::cout << "Form: " << "Default constructor called"
        << std::endl;
    this->_signed = false;
}

Form::Form(std::string const name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
    this->_signed = false;
}

Form::Form(Form const &other): _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade())
{
    *this = other;
}

Form &Form::operator=(Form const &other)
{
    this->_signed = other.getSigned();
    return *this;
}

Form::~Form()
{
    std::cout << "destructor called" << std::endl;
}

std::string const &Form::getName() const
{
    return this->_name;
}

bool Form::getSigned() const
{
    return this->_signed;
}

int Form::getSignGrade() const
{
    return this->_signGrade;
}

int Form::getExecGrade() const
{
    return this->_execGrade;
}

void Form::beSigned()
{
    this->_signed = true;
}

void Form::beExecuted()
{
    if (!this->_signed)
        throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << "Form: " << form.getName() << ", sign grade: "
        << form.getSignGrade() << ", exec grade: "
        << form.getExecGrade() << ", signed: "
        << form.getSigned();
    return out;
}