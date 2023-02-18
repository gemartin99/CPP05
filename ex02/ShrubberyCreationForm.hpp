#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

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
};

#endif;