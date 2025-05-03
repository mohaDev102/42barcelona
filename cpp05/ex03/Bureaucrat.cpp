#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat exception: grade is too high";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat exception: grade is too low";
}

Bureaucrat::Bureaucrat() : name("default"), grade(MIN_GRADE) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    if (grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (grade > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.getName()) {
    if (other.getGrade() < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (other.getGrade() > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    this->grade = other.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    (void) other;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::signAForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << "Bureaucrat " << this->name << " signed format "
        << form.getName() << std::endl;
    } catch(const AForm::GradeTooLowException& e) {
        std::cerr << "Bureaucrat " << this->name << " can't sign format "
        << form.getName() << " because its grade is too low" << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) {
    try {
        form.execute(*this);
        std::cout << "Bureaucrat " << this->name << " executed format "
        << form.getName() << std::endl;
    } catch (const AForm::GradeTooLowException& e) {
        std::cerr << "Bureaucrat " << this->name << " can't execute format "
        << form.getName() << " because its grade is too low " << std::endl;
    } catch (const AForm::FormNotSignedException& e) {
        std::cerr << "Bureaucrat " << this->name << " can't execute format "
        << form.getName() << " because it is not signed " << std::endl;
    }
}

void Bureaucrat::incrementGrade() {
    if (this->grade - 1 < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->grade + 1 > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

std::string Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { return this->grade; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}