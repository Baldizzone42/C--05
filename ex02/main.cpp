/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:55:45 by jormoral          #+#    #+#             */
/*   Updated: 2025/05/13 20:43:12 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat sergio("alias masturbado", 5);
	ShrubberyCreationForm telefonica("setgio");
	std::cout << telefonica.getGradeToSign() << std::endl;
	std::cout << telefonica.getGradeToExecute() << std::endl;
	std::cout << telefonica.getName() << std::endl;
	std::cout << telefonica.getSigned() << std::endl;
	//ShrubberyCreationForm pepi;
	//RobotomyRequestForm pedro;
	//buro.signForm(pedro);
	//buro.executeForm(pedro);
	return 0;
}