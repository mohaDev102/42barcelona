#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class AForm;

class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signAForm(AForm& form);
    void executeForm(AForm const & form);

    class GradeTooHighException : public std::exception {
    public:
        GradeTooHighException();
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        GradeTooLowException();
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif