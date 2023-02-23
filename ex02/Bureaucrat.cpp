#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
	//std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	//std::cout << "Bureaucrat default destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): name(copy.name)
{
	this->grade = copy.grade;
	//std::cout << "Bureaucrat copy constructor called" << std::endl;
}

std::ostream & operator<<(std::ostream& os, const Bureaucrat & B)
{
	os << B.getName() << " , bureaucrat grade " << B.getGrade() << "." << std::endl;
	return os;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other)
{

	//std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	this->grade = other.grade;
	return *this;
}

std::string Bureaucrat::getName(void) const
{
	return this->name;
}

int Bureaucrat::getGrade(void) const
{
	return this->grade;
}

void Bureaucrat::incrementGrade(void)
{
	checkGrade(this->grade - 1);
	/*if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;*/
}

void Bureaucrat::decrementGrade(void)
{
	checkGrade(this->grade + 1);
	/*if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;*/
}

void Bureaucrat::setGrade(int grade)
{
	this->grade = grade;
}

void Bureaucrat::checkGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
			setGrade(grade);
}

void Bureaucrat::signForm(AForm & form) const
{
	if (form.getSGrade() < this->grade)
		std::cout << this->name << " couldn’t sign " <<  form.getName() << " the bureaucrat's grade is lower than required to be able to sign." << std::endl;
	else
		std::cout << this->name << " signed " << form.getName() << std::endl;
	form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const & form) const
{
	if (form.getEGrade() < this->grade || form.getSign() == false)
		std::cout << this->name << " couldn’t execute " <<  form.getName() << " the bureaucrat's grade is lower than required to be able to execute." << std::endl;
	else
		std::cout << this->name << " executed " << form.getName() << std::endl;
}
