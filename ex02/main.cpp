#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "--- Teste 1: ShrubberyCreationForm ---" << std::endl;
    try {
        Bureaucrat b("Alice", 137);
        ShrubberyCreationForm f("home");
        std::cout << f;
        b.signForm(f);
        b.executeForm(f);
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n--- Teste 2: Shrubbery sem assinar ---" << std::endl;
    try {
        Bureaucrat b("Bob", 140);
        ShrubberyCreationForm f("garden");
        b.executeForm(f);
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n--- Teste 3: RobotomyRequestForm ---" << std::endl;
    try {
        Bureaucrat b("Carlos", 40);
        RobotomyRequestForm f("Marvin");
        std::cout << f;
        b.signForm(f);
        b.executeForm(f);
        b.executeForm(f);
        b.executeForm(f);
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n--- Teste 4: RobotomyRequestForm grade insuficiente para executar ---" << std::endl;
    try {
        Bureaucrat signer("Diana", 40);
        Bureaucrat executor("Eve", 50);
        RobotomyRequestForm f("Target");
        signer.signForm(f);
        executor.executeForm(f);
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n--- Teste 5: PresidentialPardonForm ---" << std::endl;
    try {
        Bureaucrat b("Zaphod", 3);
        PresidentialPardonForm f("Ford");
        std::cout << f;
        b.signForm(f);
        b.executeForm(f);
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n--- Teste 6: PresidentialPardonForm grade insuficiente para assinar ---" << std::endl;
    try {
        Bureaucrat b("Low", 50);
        PresidentialPardonForm f("Arthur");
        b.signForm(f);
        b.executeForm(f);
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    return 0;
}