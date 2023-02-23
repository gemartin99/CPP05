#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int	main(void)
{
	AForm			*form = NULL;
	Bureaucrat		bob("bob", 1);
	Bureaucrat		phil("phil", 46);
	Bureaucrat		luc("luc", 150);

	// std::cout << "TEST FORM IS NOW A ABSTRACT CLASS" << std::endl;
	// form = new Form("28Z");



	std::cout << "TEST EXECUTE PRESIDENTIAL FORM WHITOUT SIGN" << std::endl;
	try
	{
		form = new PresidentialPardonForm("28Z");
		std::cout << "Siganture Gade: " << form->getSGrade() << std::endl;
		std::cout << "Execution Gade: " << form->getEGrade() << std::endl;
		form->execute(bob);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		delete form;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "TEST PRESIDENTIAL FORM SIGNED AND EXECUTED BE LVL 1" << std::endl;

	try
	{
		form = new PresidentialPardonForm("28A");
		form->beSigned(bob);
		form->execute(bob);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		delete form;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "TEST PRESIDENTIAL FORM SIGNED AND EXECUTED BE LVL 150" << std::endl;
	try
	{
		form = new PresidentialPardonForm("28A");
		form->beSigned(luc);
		form->execute(luc);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		delete form;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "TEST EXECUTE ROBOTOMYREQUEST FORM WHITOUT SIGN" << std::endl;
	try
	{
		form = new RobotomyRequestForm("28Z");
		std::cout << "Siganture Gade: " << form->getSGrade() << std::endl;
		std::cout << "Execution Gade: " << form->getEGrade() << std::endl;
		form->execute(bob);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		delete form;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "TEST ROBOTOMYREQUEST FORM SIGNED AND EXECUTED BE LVL 1" << std::endl;

	try
	{
		form = new RobotomyRequestForm("28A");
		form->beSigned(bob);
		form->execute(bob);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		delete form;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "TEST ROBOTOMYREQUEST FORM SIGNED BUT NOT ENOGHT LEVEL TO EXECUTE" << std::endl;

	try
	{
		form = new RobotomyRequestForm("28A");
		phil.signForm(*form);
		form->execute(phil);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		delete form;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "TEST ROBOTOMYREQUEST FORM SIGNED AND EXECUTED BE LVL 150" << std::endl;
	try
	{
		form = new RobotomyRequestForm("28A");
		form->beSigned(luc);
		form->execute(luc);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		delete form;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "TEST ROBOTOMYREQUEST MULTIPLE EXECUTIONS" << std::endl;
	try
	{
		form = new RobotomyRequestForm("28B");
		form->beSigned(bob);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		form->execute(phil);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		delete form;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "TEST EXECUTE SHRUBERRYCREATION FORM WHITOUT SIGN" << std::endl;
	try
	{
		form = new ShrubberyCreationForm("28Z");
		std::cout << "Siganture Gade: " << form->getSGrade() << std::endl;
		std::cout << "Execution Gade: " << form->getEGrade() << std::endl;
		form->execute(bob);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		delete form;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "TEST SHRUBERRYCREATION FORM SIGNED AND EXECUTED BE LVL 1" << std::endl;

	try
	{
		form = new ShrubberyCreationForm("28A");
		form->beSigned(bob);
		form->execute(bob);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		delete form;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "TEST SHRUBERRYCREATION FORM SIGNED AND EXECUTED BE LVL 150" << std::endl;
	try
	{
		form = new ShrubberyCreationForm("28A");
		form->beSigned(luc);
		form->execute(luc);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		delete form;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;



	try
	{
		form = new ShrubberyCreationForm("Home");
		form->beSigned(bob);
		form->execute(phil);
		form->execute(luc);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		delete form;
		std::cout << e.what() << std::endl;
	}

	// delete bob;
	// delete phil;
	// delete luc;
	return (0);
}


/*int	main(void)
{
	Bureaucrat	b1("Juan", 1);
	Bureaucrat	b2("Javier", 150);
	ShrubberyCreationForm sf("Home");
	RobotomyRequestForm rf("Man");
	PresidentialPardonForm pf("Trump");
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	b1.incrementGrade();
	std::cout << b1 << std::endl;
	b2.decrementGrade();
	std::cout << b2 << std::endl;
	std::cout << "------Forms------------" << std::endl;
	std::cout << "\n<|ShrubberyCreationForm|>\n" << std::endl;
	std::cout << sf << std::endl;
	sf.execute(b1);
	std::cout << "------------------" << std::endl;
	sf.beSigned(b1);
	sf.execute(b2);
	sf.execute(b1);
	std::cout << "\n<|RobotomyRequestForm|>\n" << std::endl;
	std::cout << rf << std::endl;
	rf.execute(b1);
	std::cout << "------------------" << std::endl;
	rf.beSigned(b1);
	rf.execute(b2);
	rf.execute(b1);
	std::cout << "\n<|PresidentialPardonForm|>\n" << std::endl;
	std::cout << pf << std::endl;
	pf.execute(b1);
	std::cout << "------------------" << std::endl;
	pf.beSigned(b1);
	pf.execute(b2);
	pf.execute(b1);
}*/