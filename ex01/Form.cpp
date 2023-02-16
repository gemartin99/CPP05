#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, const int sign_grade, const int execute_grade): name(name), sign(false), sign_grade(sign_grade), execute_grade(execute_grade)
{
	if (sign_grade < 1 || execute_grade < 1)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150 || execute_grade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form default constructor called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form default destructor called" << std::endl;
}

Form::Form(const Form &copy): name(copy.name), sign(copy.sign), sign_grade(copy.sign_grade), execute_grade(copy.execute_grade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

std::ostream & operator<<(std::ostream& os, const Form & F)
{
	os << F.getName() << " sign form grade " << F.getSGrade() << " execute grade " << F.getEGrade() << " sign " << F.getSign() << "." << std::endl;
	return os;
}

Form & Form::operator=(const Form & other)
{
	this->sign = other.sign;
	std::cout << "Form copy assignment operator called" << std::endl;
	return *this;
}

int Form::getSGrade(void) const
{
	return this->sign_grade;
}

int Form::getEGrade(void) const
{
	return this->execute_grade;
}

bool Form::getSign(void) const
{
	return this->sign;
}

std::string Form::getName(void) const
{
	return this->name;
}

void Form::beSigned(const Bureaucrat & b)
{
	if (this->sign_grade < b.getGrade())
		throw GradeTooLowException();
	this->sign = true;
}