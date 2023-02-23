#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("presidential", 25, 5), target(target)
{
	//std::cout << "presidential default constructor called" << std::endl
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	//std::cout << "presidential default destructor called" << std::endl
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy), target(copy.target)
{
	//std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{

	//std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	this->target = other.target;
	return *this;
}

void PresidentialPardonForm::_execute(Bureaucrat const & executor) const
{
	if (!this->checkExec(executor))
		return;
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}