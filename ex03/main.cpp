/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:55:45 by jormoral          #+#    #+#             */
/*   Updated: 2025/05/14 14:57:36 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Intern someRandomIntern;
	Bureaucrat buro;
	AForm *rrf;
	rrf = someRandomIntern.makeForm("Robotomy EQUEST", "gdfg");
	buro.signForm(*rrf); 
	rrf->beSigned(buro);
	rrf->execute(buro);
	AForm *test = someRandomIntern.makeForm("PreSIDEntial pardon", "Bender");
	delete rrf;
	delete test;
	/* Bureaucrat blo("manin", 5);
	//PresidentialPardonForm Manolo("Horse");
	//ShrubberyCreationForm pepi;
	RobotomyRequestForm pedro;
	blo.signForm(pedro);
	blo.executeForm(pedro); */
	return 0;
}