#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _name;
        bool    _isSigned;
        const int   _gradeToSign;
        const int   _gradeToExecute;

    public:
        Form();
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(Form const &copy);
        ~Form();

        Form& operator=(const Form &other);
        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void    beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif
