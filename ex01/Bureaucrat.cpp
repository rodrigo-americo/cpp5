#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat:: Bureaucrat(const std::string name, int grade) : name(name) {
    setGrade(grade);
}

Bureaucrat:: Bureaucrat(const Bureaucrat &other) : name(other.name) {
    setGrade(other.grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        setGrade(other.grade);
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << name << " destroyed" << std::endl;
}

std::string Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::setGrade(int grade) {

    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

void Bureaucrat::incrementGrade() {
    setGrade(grade - 1);
}

void Bureaucrat::decrementGrade() {
    setGrade(grade + 1);
}

void Bureaucrat::signForm(Form &form) const {
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signs " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << this->name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", burocrata com classificação " << bureaucrat.getGrade() << std::endl;
    return os;
}
