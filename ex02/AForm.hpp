#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;
class AForm
{
private:
	std::string const name;
	bool	sign;
	const int sign_grade;
	const int execute_grade;
protected:
	AForm(void);
	virtual void _execute(const Bureaucrat& executor) const = 0;
public:
	AForm(std::string name, const int sign_grade, const int execute_grade);
	virtual ~AForm(void);
	std::string getName(void) const;
	bool getSign(void) const;
	int getSGrade(void) const;
	int getEGrade(void) const;
	void	setSGrade(void);
	void	setEGrade(void);
	void beSigned(const Bureaucrat & b);
	AForm& operator=(const AForm & other);
	AForm(const AForm& copy);
	bool	checkExec(Bureaucrat const &) const;
	void execute(Bureaucrat const & executor) const;
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
    class GradeNoSignException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: the form must be signed in order to be executed";
        }
    };
};

std::ostream & operator<<(std::ostream& os, const AForm & F);

#endif