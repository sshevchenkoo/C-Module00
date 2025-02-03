#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat highRanker("Alice", 1);
        Bureaucrat lowRanker("Bob", 150);

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "HighRanker tries to sign ShrubberyCreationForm:" << std::endl;
        try {
            shrubbery.beSigned(highRanker);
            std::cout << "ShrubberyCreationForm signed successfully." << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "HighRanker tries to sign RobotomyRequestForm:" << std::endl;
        try {
            robotomy.beSigned(highRanker);
            std::cout << "RobotomyRequestForm signed successfully." << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "HighRanker tries to sign PresidentialPardonForm:" << std::endl;
        try {
            pardon.beSigned(highRanker);
            std::cout << "PresidentialPardonForm signed successfully." << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "LowRanker tries to execute ShrubberyCreationForm:" << std::endl;
        try {
            shrubbery.execute(lowRanker);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "HighRanker executes ShrubberyCreationForm:" << std::endl;
        try {
            shrubbery.execute(highRanker);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "HighRanker executes RobotomyRequestForm:" << std::endl;
        try {
            robotomy.execute(highRanker);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "HighRanker executes PresidentialPardonForm:" << std::endl;
        try {
            pardon.execute(highRanker);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
