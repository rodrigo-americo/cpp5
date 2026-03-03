#include "bureaucrat.hpp"

int main() {
  std::cout << "--- Test 1: Valid Bureaucrats ---" << std::endl;
  try {
    Bureaucrat b1("Alice", 1);
    std::cout << b1;
    Bureaucrat b2("Bob", 150);
    std::cout << b2;
    Bureaucrat b3("Charlie", 75);
    std::cout << b3;
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n--- Test 2: Invalid Bureaucrat (Grade too high) ---"
            << std::endl;
  try {
    Bureaucrat invalid1("TooHigh", 0);
    std::cout << invalid1;
  } catch (std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "\n--- Test 3: Invalid Bureaucrat (Grade too low) ---"
            << std::endl;
  try {
    Bureaucrat invalid2("TooLow", 151);
    std::cout << invalid2;
  } catch (std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "\n--- Test 4: Increment Grade ---" << std::endl;
  try {
    Bureaucrat b("Dave", 2);
    std::cout << "Before: " << b;
    b.incrementGrade();
    std::cout << "After increment: " << b;
    b.incrementGrade(); // Should throw here (grade 1 -> 0)
    std::cout << "After increment again: " << b;
  } catch (std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "\n--- Test 5: Decrement Grade ---" << std::endl;
  try {
    Bureaucrat b("Eve", 149);
    std::cout << "Before: " << b;
    b.decrementGrade();
    std::cout << "After decrement: " << b;
    b.decrementGrade(); // Should throw here (grade 150 -> 151)
    std::cout << "After decrement again: " << b;
  } catch (std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "\n--- Tests Completed ---" << std::endl;
  return 0;
}