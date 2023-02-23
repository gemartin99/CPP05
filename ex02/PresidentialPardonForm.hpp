#ifndef	PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class Aform;
class PresidentialPardonForm: public AForm
{
private:
	std::string target;
	PresidentialPardonForm(void);
public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm(void);
	PresidentialPardonForm& operator=(const PresidentialPardonForm & other);
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	virtual void _execute(Bureaucrat const & executor) const;
};

#endif