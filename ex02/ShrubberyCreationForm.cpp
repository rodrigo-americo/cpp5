#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), target(target) {
    std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), target(other.target) {
    std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    AForm::checkExecution(executor);
    std::ofstream ofs((target + "_shrubbery").c_str());
    if (!ofs.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
    ofs << "      /\\      " << std::endl;
    ofs << "     /  \\     " << std::endl;
    ofs << "    /    \\    " << std::endl;
    ofs << "   /______\\   " << std::endl;
    ofs << "  /        \\  " << std::endl;
    ofs << " /__________\\ " << std::endl;
    ofs << "/____________\\" << std::endl;
    ofs.close();
}