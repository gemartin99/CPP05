#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int	main(void)
{
	srand(time(NULL));
	Intern someIntern;

	Bureaucrat supervisor("Supervisor", 1);
	Bureaucrat francis("Francis", 25);

	AForm *shrub = someIntern.makeForm("shrubbery", "home");
	shrub->beSigned(supervisor);
	shrub->execute(francis);

	AForm *pres = someIntern.makeForm("presidential", "Francis");
	supervisor.signForm(*pres);
	pres->execute(supervisor);

	AForm *robot = someIntern.makeForm("robotomy", "Bender");
	robot->beSigned(supervisor);
	robot->execute(francis);
	francis.executeForm(*robot);
	francis.executeForm(*robot);

	try
	{
		AForm *fake = someIntern.makeForm("fake request", "Bender");
		delete fake;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	delete shrub;
	delete pres;
	delete robot;
	return (0);
}
