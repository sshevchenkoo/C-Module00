#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), _target("null") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }
    std::ofstream	file;
	file.open((this->_target + "_shrubbery").c_str());
    if (file.fail())
    {
        std::cout << "Could not open output file" << std::endl;
        return ;
    }
    file << "       _-_\n";
    file << "    /~~   ~~\\n";
    file << " /~~         ~~\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "      // \\\n";

    std::cout << "ShrubberyCreationForm executed: created " << _target + "_shrubbery" << std::endl;

    file.close();
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

std::ostream &operator<<(std::ostream &str, ShrubberyCreationForm const &form) {
    str << "Form: " << form.getName() 
        << ", Target: " << form.getTarget()
        << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Sign Grade: " << form.getGradeToSign()
        << ", Execute Grade: " << form.getGradeToExecute();
    return str;
}