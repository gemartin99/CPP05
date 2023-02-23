#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern(void);
	~Intern(void);
	Intern& operator=(const Intern & other);
	Intern(const Intern& copy);
	AForm* makeForm(std::string const &s1, std::string const &s2);
};

#endif