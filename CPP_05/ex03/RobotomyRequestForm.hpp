#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <fstream>
#include <cstdlib>

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		~RobotomyRequestForm();

		RobotomyRequestForm const	&operator=(RobotomyRequestForm const &other);

		void	execute(Bureaucrat const &bureaucrat) const;
        std::string getTarget() const;
};

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form);

#endif