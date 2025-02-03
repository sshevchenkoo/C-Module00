#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string _name;
        bool    _isSigned;
        const int   _gradeToSign;
        const int   _gradeToExecute;

    public:
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(AForm const &copy);
        virtual ~AForm();

        AForm& operator=(const AForm &other);
        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void    beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;

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
        class FormNotSignedException: public std::exception // Добавить здесь
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif
