#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Carlos", 147);
	std::cout << a;
	a.decrementGrade();
	std::cout << a;
	a.decrementGrade();
	std::cout << a;
	a.decrementGrade();
	std::cout << a;
	a.decrementGrade();
	std::cout << a;
	a.decrementGrade();
	std::cout << a;
	return (0);
}