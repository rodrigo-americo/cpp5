#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), target(target) {
    std::cout << "PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), target(other.target) {
    std::cout << "PresidentialPardonForm copy constructor" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    AForm::checkExecution(executor);
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}