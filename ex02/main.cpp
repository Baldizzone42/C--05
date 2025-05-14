/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:55:45 by jormoral          #+#    #+#             */
/*   Updated: 2025/05/14 14:59:06 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat sergio("benitez", 5);
	PresidentialPardonForm telefonica("Jc");
	ShrubberyCreationForm tree("Joe pesci");
	RobotomyRequestForm gabri("Fred");
	sergio.signForm(telefonica);
	telefonica.execute(sergio);
	std::cout << std::endl;
	tree.beSigned(sergio);
	tree.execute(sergio);
	std::cout << std::endl;
	gabri.beSigned(sergio);
	gabri.execute(sergio);

	std::cout << std::endl;
	
	/* tree.concrete_execute(sergio);
	gabri.concrete_execute(sergio); */
	return 0;
}

//shrubbery sign 145 exec 137
//Robotomy sign 72 exec 45
//Presidential sign 25 exec 5