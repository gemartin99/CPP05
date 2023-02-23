#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class Aform;
class ShrubberyCreationForm : public AForm
{
private:
	std::string target;
	ShrubberyCreationForm(void);
public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm & other);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	void _execute(Bureaucrat const & executor) const;
};

#endif