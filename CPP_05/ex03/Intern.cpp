#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

AForm* Intern::makeForm(const std::string& class_name, const std::string& name)
{
    const std::string formNames[] = {
        "robotomy request",
        "shrubbery creation",
        "presidential pardon"
    };

    AForm* (*formCreators[])(const std::string&) = {
        [](const std::string& target) -> AForm* { return new RobotomyRequestForm(target); },
        [](const std::string& target) -> AForm* { return new ShrubberyCreationForm(target); },
        [](const std::string& target) -> AForm* { return new PresidentialPardonForm(target); }
    };

    const size_t formCount = sizeof(formNames) / sizeof(formNames[0]);

    for (size_t i = 0; i < formCount; ++i)
    {
        if (formNames[i] == class_name)
            return formCreators[i](name);
    }

    std::cerr << "Error: Form '" << class_name << "' does not exist!" << std::endl;
    return nullptr;
}
