#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat; 

class AForm {
public:
    class GradeTooHighException : public std::exception {
    public:
        GradeTooHighException();
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        GradeTooLowException();
        const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        FormNotSignedException();
        const char *what() const throw();
    };

    AForm();
    AForm(const std::string& name, int signGrade, int executeGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    void beSigned(const Bureaucrat& bureaucrat);
    void execute(Bureaucrat const & executor);
    virtual void action() const = 0;
    
    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;
};

std::ostream&  operator<<(std::ostream& os, const AForm& obj);

#endif