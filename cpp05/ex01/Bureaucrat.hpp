#ifndef BUERAUCRAT_HPP
#define BUERAUCRAT_HPP

#include "Form.hpp"
#include <iostream>
#include <exception>

#define MIN_GRADE 150
#define MAX_GRADE 1

class Form;

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();
    std::string const &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form& form);

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};
std::ostream &operator<<(std::ostream &out, Bureaucrat const &bure);
#endif