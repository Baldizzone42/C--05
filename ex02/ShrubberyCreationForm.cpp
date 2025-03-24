/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:12:37 by jormoral          #+#    #+#             */
/*   Updated: 2025/03/24 16:07:41 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), target("") {
	std::cout << "Presidential Form Constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", false, 145, 137), target(target) {
	std::cout << "Presidential Form Constructor\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "Destructor Shrubbery form\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :target(other.target)
{
	std::cout << "Copy Shrubbery Form" << std::endl;
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "Assignment Shrubbery Form\n";
	if(this != &other)
		*this = other;
	return *this;
}

int ShrubberyCreationForm::concrete_execute(Bureaucrat const & executor) const
{
	try
	{
		if(executor.getGrade() > this->getGradeToExecute())
			throw(AForm::GradeTooLowException());
		if (this->getSigned() == false)
			throw(AForm::ItWasntSignedException());
		if(this->getSigned() == true)
		{
			
			std::ofstream out((this->target + "_shrubbery").c_str());
			if(out.fail())
			{
				std::cout << "Wrong opening\n";
				return 1;
			}
			out << "             _.-=-._                                    " << std::endl;
			out << "           o~`  '  ~o                                  " << std::endl;
			out << "        _-~o~       ~o~-_                              " << std::endl;
			out << "      .-~               ~-.                            " << std::endl;
			out << "    .~                     ~.                         " << std::endl;
			out << "   /                         \\                        " << std::endl;
			out << "  ;                           ;                        " << std::endl;
			out << "  |                           |                        " << std::endl;
			out << "  ;      _.-=-._.-=-._        ;                        " << std::endl;
			out << "   \\    o~`  '  ~o~`  'o     /                         " << std::endl;
			out << "    `.  ~-._.-._.-._.-~     .'                          " << std::endl;
			out << "      `-.                 .-'                            " << std::endl;
			out << "         ~-._         _.-~                              " << std::endl;
			out << "             `-------'                                  " << std::endl;
			out << "                 |||                                    " << std::endl;
			out << "                 |||                                    " << std::endl;
			out << "                 |||                                    " << std::endl;
			out << "              ___|||___                                 " << std::endl;
			out << "             /         \\                               " << std::endl;
			out << "            /___________\\                              " << std::endl;
			out.close();
			return 0;
		}
	}
	catch(std::exception & e)
	{
		std::cerr << e.what();
		return(1);
	}
	return 0;

	
}