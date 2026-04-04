#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static AForm *createShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}
static AForm *createRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}
static AForm *createPardon(std::string target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern() {
    std::cout << "Intern constructor" << std::endl;
}

Intern::Intern(const Intern &other) {
    (void)other;
    std::cout << "Intern copy constructor" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    std::cout << "Intern assignment operator" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor" << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string target) {
    FormEntry forms[] = {
        {"shrubbery creation", &createShrubbery},
        {"criação de arbusto", &createShrubbery},
        {"robotomy request", &createRobotomy},
        {"pedido de robotomia", &createRobotomy},
        {"presidential pardon", &createPardon},
        {"perdão presidencial", &createPardon}
    };
    for (int i = 0; i < 6; i++) {
        if (forms[i].name == formName) {
            std::cout << "Intern cria " << formName << std::endl;
            return forms[i].create(target);
        }
    }
    std::cerr << "Intern: formulário desconhecido: " << formName << std::endl;
    return NULL;
}
