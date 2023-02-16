#ifndef BUREAUCRAT_HPP		
# define BUREAUCRAT_HPP

#include "Form.hpp"
#include <string>
#include <iostream>

class Bureaucrat
{
private:
	const std::string name;
	int grade;
	Bureaucrat(void);
	void checkGrade(int grade);
public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat(void);
	std::string getName(void) const;
	int getGrade(void) const;
	Bureaucrat& operator=(const Bureaucrat & other);
	Bureaucrat(const Bureaucrat& copy);
	void incrementGrade(void);
	void decrementGrade(void);
	void setName(std::string name);
	void setGrade(int grade);
	void signForm(Form & form) const;
	class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: the bureaucrat grade is too high";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: the bureaucrat grade is too low";
        }
    };
};

std::ostream & operator<<(std::ostream& os, const Bureaucrat & B);

#endif