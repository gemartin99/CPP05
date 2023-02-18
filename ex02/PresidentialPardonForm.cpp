#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("presidential", 25, 5), target(target)
{
	//std::cout << "presidential default constructor called" << std::endl
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	//std::cout << "presidential default destructor called" << std::endl
}