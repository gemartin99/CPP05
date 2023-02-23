#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, const int sign_grade, const int execute_grade): name(name), sign(false), sign_grade(sign_grade), execute_grade(execute_grade)
{
	if (sign_grade < 1 || execute_grade < 1)
		throw AForm::GradeTooHighException();
	else if (sign_grade > 150 || execute_grade > 150)
		throw AForm::GradeTooLowException();
	//std::cout << "AForm default constructor called" << std::endl;
}

AForm::~AForm(void)
{
	//std::cout << "AForm default destructor called" << std::endl;
}

AForm::AForm(const AForm &copy): name(copy.name), sign(copy.sign), sign_grade(copy.sign_grade), execute_grade(copy.execute_grade)
{
	//std::cout << "AForm copy constructor called" << std::endl;
}

std::ostream & operator<<(std::ostream& os, const AForm & F)
{
	os << F.getName() << " sign AForm grade " << F.getSGrade() << " execute grade " << F.getEGrade() << " sign " << F.getSign() << "." << std::endl;
	return os;
}

AForm & AForm::operator=(const AForm & other)
{
	this->sign = other.sign;
	//std::cout << "AForm copy assignment operator called" << std::endl;
	return *this;
}

int AForm::getSGrade(void) const
{
	return this->sign_grade;
}

int AForm::getEGrade(void) const
{
	return this->execute_grade;
}

bool AForm::getSign(void) const
{
	return this->sign;
}

std::string AForm::getName(void) const
{
	return this->name;
}

void AForm::execute(const Bureaucrat& b) const
{
	b.executeForm(*this);
	if (this->sign == false)
		throw AForm::GradeNoSignException();
	if (this->execute_grade < b.getGrade())
		throw AForm::GradeTooLowException();
	_execute(b);
}

void AForm::beSigned(const Bureaucrat & b)
{
	if (this->sign_grade < b.getGrade())
		throw AForm::GradeTooLowException();
	this->sign = true;
}

bool	AForm::checkExec(Bureaucrat const & executor) const
{
	if (this->sign == false)
	{
		throw AForm::GradeNoSignException();
		return (false);
	}
	else if (this->execute_grade >= executor.getGrade())
		return (true);
	else
	{
		throw AForm::GradeNoSignException();
		return (false);
	}
}