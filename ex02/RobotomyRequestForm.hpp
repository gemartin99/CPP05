#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

class RobotomyRequestForm: public AForm
{
private:
	std::string target;
	RobotomyRequestForm(void);
public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm(void);
	RobotomyRequestForm& operator=(const RobotomyRequestForm & other);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
};

#endif;