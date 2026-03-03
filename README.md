# CPP Module 05 - Repetition and Exceptions

**42 School Project** | C++98 | Exception Handling

---

## 🎯 Overview

Implementation of exception handling in C++98 through a bureaucratic office simulation. Progressing from basic try/catch mechanics to a full form-signing and execution pipeline with nested exception classes and abstract forms.

**Tech Stack**: C++98 | Exceptions | Abstract Classes | Orthodox Canonical Form | Nested Exception Classes

---

## 📐 Class Hierarchy

```
Exception System                    Class Structure
────────────────                    ───────────────

std::exception                         Bureaucrat
      │                                    │
      ├── Bureaucrat::GradeTooHighException │ signForm()
      ├── Bureaucrat::GradeTooLowException  │ executeForm()
      │                                     │
      ├── AForm::GradeTooHighException    AForm (abstract)
      └── AForm::GradeTooLowException        │
                                             ├── ShrubberyCreationForm
                                             │     sign: 145 / exec: 137
                                             │
                                             ├── RobotomyRequestForm
                                             │     sign: 72 / exec: 45
                                             │
                                             └── PresidentialPardonForm
                                                   sign: 25 / exec: 5

                                          Intern
                                             │ makeForm(name, target)
                                             │ array of function pointers
                                             └── returns AForm*
```

---

## 📋 Exercises Summary

| Exercise | Focus | Key Components | Challenge |
|----------|-------|----------------|-----------|
| **ex00** | Basic Exceptions | `Bureaucrat` with nested exception classes | `throw()` specifier, try/catch flow |
| **ex01** | Form Signing | `Form` class with `beSigned()` | Exception propagation across classes |
| **ex02** | Abstract Forms | `AForm` + 3 concrete forms | `checkExecution()` in base, virtual destructor |
| **ex03** | Intern Pattern | `Intern::makeForm()` | Function pointer array, no if/else chains |

---

## 🔧 Technical Implementation

### Nested Exception Classes
Each class owns its exception types as nested classes inheriting from `std::exception`:

```cpp
class Bureaucrat {
    public:
        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };
};
```

### Exception Propagation Pattern
Exceptions are thrown deep and caught at the top — `setGrade` throws, caller catches:

```cpp
// setGrade throws, never catches
void Bureaucrat::setGrade(int grade) {
    if (grade < 1)  throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();
    this->grade = grade;
}

// main catches
try { Bureaucrat b("Alice", 0); }
catch (std::exception &e) { std::cout << e.what() << std::endl; }
```

### checkExecution in Base Class
Validation logic centralized in `AForm` to avoid duplication across concrete forms:

```cpp
void AForm::checkExecution(Bureaucrat const &executor) const {
    if (!isSigned)
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}
```

### Intern — Function Pointer Array
`makeForm()` uses an array of structs instead of if/else chains:

```cpp
struct FormEntry {
    std::string name;
    AForm *(*create)(std::string target);
};

FormEntry forms[] = {
    {"shrubbery creation", &createShrubbery},
    {"robotomy request",   &createRobotomy},
    {"presidential pardon", &createPardon}
};
```

---

## ⚙️ Compilation & Testing

### Build
```bash
make        # Compile
make clean  # Remove objects
make fclean # Remove objects + executable
make re     # Rebuild
```

**Flags**: `-Wall -Wextra -Werror -std=c++98`

---

## 📊 Results

- ✅ **Grade validation** enforced at construction and mutation
- ✅ **Exception propagation** verified — exceptions reach main correctly
- ✅ **Abstract enforcement** — AForm cannot be instantiated directly
- ✅ **Intern dispatch** — correct form created without if/else chains
- ✅ **50% robotomy** randomness verified across multiple executions

---

## 🎓 Key Learnings

**Exception Mechanics**
- `throw` propagates up the call stack until a matching `catch` is found
- Catching in the wrong place (inside the thrower) silently swallows errors
- `const throw()` — old exception specification required by C++98

**Design Patterns**
- Nested exception classes keep error types scoped to their owner
- `checkExecution()` in base class avoids code duplication in derived forms
- Function pointer arrays replace if/else chains for clean dispatch

**Pitfalls**
- Virtual destructor required on `AForm` for safe `delete` through base pointer
- `std::ofstream` in C++98 requires `.c_str()` — does not accept `std::string`

---

## 📁 Project Structure

```
cpp05/
├── ex00/                   # Bureaucrat + nested exceptions
│   ├── Bureaucrat.{hpp,cpp}
│   └── main.cpp
├── ex01/                   # Form signing
│   ├── Bureaucrat.{hpp,cpp}
│   ├── Form.{hpp,cpp}
│   └── main.cpp
├── ex02/                   # Abstract forms
│   ├── Bureaucrat.{hpp,cpp}
│   ├── AForm.{hpp,cpp}
│   ├── ShrubberyCreationForm.{hpp,cpp}
│   ├── RobotomyRequestForm.{hpp,cpp}
│   ├── PresidentialPardonForm.{hpp,cpp}
│   └── main.cpp
└── ex03/                   # Intern
    ├── Bureaucrat.{hpp,cpp}
    ├── AForm.{hpp,cpp}
    ├── ShrubberyCreationForm.{hpp,cpp}
    ├── RobotomyRequestForm.{hpp,cpp}
    ├── PresidentialPardonForm.{hpp,cpp}
    ├── Intern.{hpp,cpp}
    └── main.cpp
```

---

**Standard**: C++98 | **Year**: 2026
