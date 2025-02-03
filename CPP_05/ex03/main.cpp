 #include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testSigningAndExecuting(Bureaucrat &signer, Bureaucrat &executor, AForm &form) {
    std::cout << "\n=== Testing " << form.getName() << " ===\n";
    std::cout << form << std::endl;

    try {
        form.beSigned(signer);
        std::cout << signer.getName() << " signed " << form.getName() << "\n";
    } catch (const std::exception &e) {
        std::cerr << "Error while signing: " << e.what() << std::endl;
    }

    std::cout << "After signing attempt:\n" << form << std::endl;

    try {
        form.execute(executor);
        std::cout << executor.getName() << " executed " << form.getName() << "\n";
    } catch (const std::exception &e) {
        std::cerr << "Execution failed: " << e.what() << std::endl;
    }
}

int main() {
    try {
        Bureaucrat highRanker("Alice", 1);
        Bureaucrat midRanker("Charlie", 50);
        Bureaucrat lowRanker("Bob", 150);

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        testSigningAndExecuting(highRanker, highRanker, shrubbery);
        testSigningAndExecuting(highRanker, highRanker, robotomy);
        testSigningAndExecuting(highRanker, highRanker, pardon);

        std::cout << "\n=== Testing failure cases ===\n";

        try {
            shrubbery.beSigned(lowRanker);
        } catch (const std::exception &e) {
            std::cerr << "Signing error: " << e.what() << std::endl;
        }

        ShrubberyCreationForm anotherShrubbery("garden");
        try {
            anotherShrubbery.execute(highRanker);
        } catch (const std::exception &e) {
            std::cerr << "Execution error: " << e.what() << std::endl;
        }

        try {
            pardon.execute(midRanker);
        } catch (const std::exception &e) {
            std::cerr << "Execution error: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
    }

    return 0;
}
