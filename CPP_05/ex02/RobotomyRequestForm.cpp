#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other): AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm const	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	if (!getIsSigned())
		throw FormNotSignedException();
    srand((unsigned) time(NULL));
	if (std::rand() % 2) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << _target << " failed!" << std::endl;
    }
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->_target;
}

std::ostream &operator<<(std::ostream &str, RobotomyRequestForm const &form) {
    str << "Form: " << form.getName() 
        << ", Target: " << form.getTarget()
        << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Sign Grade: " << form.getGradeToSign()
        << ", Execute Grade: " << form.getGradeToExecute();
    return str;
}