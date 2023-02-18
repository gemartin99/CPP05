#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("robotomy", 72, 45), target(target)
{
	//std::cout << "Robotomy default constructor called" << std::endl
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	//std::cout << "Robotomy default destructor called" << std::endl
}