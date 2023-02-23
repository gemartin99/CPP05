#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("robotomy", 72, 45), target(target)
{
	//std::cout << "Robotomy default constructor called" << std::endl
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	//std::cout << "Robotomy default destructor called" << std::endl
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm(copy), target(copy.target)
{
	//std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{

	//std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	this->target = other.target;
	return *this;
}

void RobotomyRequestForm::_execute(Bureaucrat const & executor) const
{
	srand(time(0));
	if (!this->checkExec(executor))
		return;
	int i = rand();
	if (i % 2 == 0)
		std::cout << "Some drilling noises... " << this->target << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}
