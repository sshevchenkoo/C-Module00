#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat john("John", 2);
        std::cout << john << std::endl;

        john.incrementGrade();
        std::cout << john << std::endl;

        john.incrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bob("Bob", 151);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}