#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
class Bureaucrat;
class Form
{
private:
	std::string const name;
	bool	sign;
	const int sign_grade;
	const int execute_grade;
	Form(void);
public:
	Form(std::string name, const int sign_grade, const int execute_grade);
	virtual ~Form(void);
	std::string getName(void) const;
	bool getSign(void) const;
	int getSGrade(void) const;
	int getEGrade(void) const;
	void	setSGrade(void);
	void	setEGrade(void);
	void beSigned(const Bureaucrat & b);
	Form& operator=(const Form & other);
	Form(const Form& copy);
	class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: the form grade is too high";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: the form grade is too low";
        }
    };
};

std::ostream & operator<<(std::ostream& os, const Form & F);

#endif