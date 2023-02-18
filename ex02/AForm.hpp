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
	AForm(void);
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
	class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: the AForm grade is too high";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: the AForm grade is too low";
        }
    };
};

std::ostream & operator<<(std::ostream& os, const AForm & F);

#endif