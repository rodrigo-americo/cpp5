#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();
        AForm *makeForm(std::string formName, std::string target);
};

struct FormEntry {
    std::string name;
    AForm *(*create)(std::string target);
};

#endif
