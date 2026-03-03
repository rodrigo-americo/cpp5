#include "RobotomyRequestForm.hpp"
#include <cstdlib>


RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), target(target) {
    std::cout << "RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), target(other.target) {
    std::cout << "RobotomyRequestForm copy constructor" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    AForm::checkExecution(executor);
    std::cout << "* Bzzzzzz... *" << std::endl;
    if (rand() % 2 == 0) {
        std::cout << target << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << target << " has failed to be robotomized" << std::endl;
    }
}
