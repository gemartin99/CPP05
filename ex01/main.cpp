#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "INTENTO CREAR DOS FORMS CON SIGNATURE GRADE 0 Y 151" << std::endl;

	try
	{
		Form f1("F0001", 10, 0);
		std::cout << "Parece que funciona bien" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form f2("F0002", 10, 151);
		std::cout << "Parece que funciona bien" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nINTENTO CREAR DOS FORMS CON EXECUTION GRADE 0 Y 151" << std::endl;

	try
	{
		Form f3("F0003", 0, 10);
		std::cout << "Parece que funciona bien" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form f4("F0004", 151, 10);
		std::cout << "Parece que funciona bien" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nINTENTO FIRMAR UN FORMULARIO SIN EL LVL CORRECTO" << std::endl;
	try
	{
		Bureaucrat	Marc = Bureaucrat("Marc", 150);
		Form f5("F0005", 1, 10);
		std::cout << f5 << std::endl;
		Marc.signForm(f5);
		std::cout << f5 << std::endl;
		std::cout << "Parece que funciona bien" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nINTENTO FIRMAR UN FORMULARIO CON EL LVL CORRECTO" << std::endl;
	try
	{
		Bureaucrat	Marc = Bureaucrat("Marc", 1);
		Form f6("F0006", 1, 1);
		std::cout << f6 << std::endl;
		Marc.signForm(f6);
		std::cout << f6 << std::endl;
		std::cout << "Parece que funciona bien" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nINTENTO FIRMAR UN FORMULARIO DESDE EL PROPIO FORMULARIO SIN GRADO SUFICIENTE" << std::endl;
	try
	{
		Bureaucrat	Marc = Bureaucrat("Marc", 150);
		Form f8("F0005", 1, 10);
		std::cout << f8 << std::endl;
		f8.beSigned(Marc);
		std::cout << f8 << std::endl;
		std::cout << "Parece que funciona bien" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << "\nTEST GETTERS" << std::endl;
	Form f7("F0007", 10, 101);
	std::cout << "Formualrio name: " << f7.getName() << std::endl;
	std::cout << "Execution Grade: " << f7.getEGrade() << std::endl;
	std::cout << "Sigture Grade: " << f7.getSGrade() << std::endl;
	std::cout << "Is signed: " << f7.getSign() << std::endl;


	return(0);
}