#include "AForm.hpp"

AForm:: AForm(const std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm:: AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm &AForm:: operator=(const AForm &other){
    if (this != &other){
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm:: ~AForm() {
    std::cout << "Form " << name << " destroyed" << std::endl;
}

std::string AForm:: getName() const{
    return this->name;
}

bool AForm:: getSigned() const{
    return this->isSigned;
}

int AForm:: getGradeToSign() const{
    return this->gradeToSign;
}

int AForm:: getGradeToExecute() const{
    return this->gradeToExecute;
}

bool AForm:: beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > this->gradeToSign){
        throw GradeTooLowException();
    }
    this->isSigned = true;
    return true;
}

const char *AForm::GradeTooHighException::what() const throw(){
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw(){
    return "Grade too low";
}

void AForm::checkExecution(Bureaucrat const &executor) const {
    if (!isSigned)
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &form){
    os << "Form " << form.getName() << " is " << (form.getSigned() ? "signed" : "not signed") << std::endl;
    return os;
}

