#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm* Intern::makeForm(std::string const & s1, std::string const& s2)
{
	AForm* res;
	enum temp {presidential, robotomy, shrubbery};
	std::string	array[3] = {"presidential", "robotomy", "shrubbery"};
	res = NULL;
	int i;
	i = -1;
	while (++i < 4)
		if (s1 == array[i])
			break ;
	switch (i)
	{
		case presidential:
			std::cout << "Intern creates presidential" << std::endl;
			res = (new PresidentialPardonForm(s2));
			break;

		case robotomy:
			std::cout << "Intern creates robotomy" << std::endl;
			res = (new RobotomyRequestForm(s2));
			break;

		case shrubbery:
			std::cout << "Intern creates shrubbery" << std::endl;
			res =  (new ShrubberyCreationForm(s2));
			break;

		default:
			std::cout << "Intern can't create the form" << std::endl;
			break;
	}
	return (res);
}

Intern::Intern()
{}

Intern::~Intern()
{}


Intern::Intern(const Intern & copy)
{
	(void)copy;
}

Intern & Intern::operator=(const Intern & other)
{
	(void)other;
	return *this;
}