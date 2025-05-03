#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default")
{
    std::cout << "Bureaucrat: " << "Default constructor called"
		<< std::endl;
    this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    this->_grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "destructor called" << std::endl;
}

std::string const &Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << "Bureaucrat " << this->_name << " signed format "
        << form.getName() << std::endl;
    } catch(const Form::GradeTooLowException& e) {
        std::cerr << "Bureaucrat " << this->_name << " can't sign format "
        << form.getName() << " because its grade is too low" << std::endl;
    }
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

