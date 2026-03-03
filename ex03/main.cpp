#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() {
    Intern intern;

    std::cout << "\n--- Teste 1: Criar ShrubberyCreationForm ---" << std::endl;
    try {
        AForm *f = intern.makeForm("shrubbery creation", "garden");
        Bureaucrat b("Alice", 137);
        b.signForm(*f);
        b.executeForm(*f);
        delete f;
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n--- Teste 2: Criar RobotomyRequestForm ---" << std::endl;
    try {
        AForm *f = intern.makeForm("robotomy request", "Marvin");
        Bureaucrat b("Bob", 40);
        b.signForm(*f);
        b.executeForm(*f);
        delete f;
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n--- Teste 3: Criar PresidentialPardonForm ---" << std::endl;
    try {
        AForm *f = intern.makeForm("presidential pardon", "Ford");
        Bureaucrat b("Zaphod", 3);
        b.signForm(*f);
        b.executeForm(*f);
        delete f;
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n--- Teste 4: Nome de formulario invalido ---" << std::endl;
    try {
        AForm *f = intern.makeForm("banana form", "target");
        if (f)
            delete f;
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    return 0;
}