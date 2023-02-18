#ifndef	PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

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
};

#endif;