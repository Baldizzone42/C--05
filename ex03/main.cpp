/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:55:45 by jormoral          #+#    #+#             */
/*   Updated: 2025/03/25 18:59:08 by jormoral         ###   ########.fr       */
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
	AForm* rrf;
	rrf = someRandomIntern.makeForm("PreSIDEntial pardon", "Bender");
	
	delete rrf;
	/* Bureaucrat buro("manin", 5);
	//PresidentialPardonForm Manolo("Horse");
	//ShrubberyCreationForm pepi;
	RobotomyRequestForm pedro;
	buro.signForm(pedro);
	buro.executeForm(pedro); */
	return 0;
}