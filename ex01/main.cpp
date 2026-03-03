#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "--- Teste 1: Form com grade válido ---" << std::endl;
    try {
        Form f("Contrato", 50, 100);
        std::cout << f;
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n--- Teste 2: Form com gradeToSign inválido (0) ---" << std::endl;
    try {
        Form f("Inválido", 0, 100);
        std::cout << f;
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n--- Teste 3: Form com gradeToExecute inválido (200) ---" << std::endl;
    try {
        Form f("Inválido2", 50, 200);
        std::cout << f;
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n--- Teste 4: Bureaucrat com grade suficiente para assinar ---" << std::endl;
    try {
        Bureaucrat b("Alice", 30);
        Form f("Contrato", 50, 100);
        std::cout << b;
        std::cout << f;
        b.signForm(f);
        std::cout << f;
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n--- Teste 5: Bureaucrat sem grade suficiente para assinar ---" << std::endl;
    try {
        Bureaucrat b("Bob", 100);
        Form f("Contrato", 50, 100);
        std::cout << b;
        b.signForm(f);
        std::cout << f;
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n--- Teste 6: Bureaucrat com grade inválido ---" << std::endl;
    try {
        Bureaucrat b("Carlos", 0);
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    return 0;
}