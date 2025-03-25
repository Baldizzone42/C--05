/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:53:23 by jormoral          #+#    #+#             */
/*   Updated: 2025/03/25 19:01:02 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"



Intern::Intern(){
	std::cout << "Inter Default\n";
}

Intern::~Intern(){
	std::cout << "Destructor Inter\n";
}

Intern::Intern(const Intern &other)
{
	if(this != &other)
		std::cout << "Copy Intern\n";
}

Intern& Intern::operator=(const Intern &other)
{
	if(this != &other)
			*this = other;
		return *this;
}

std::string check_str(std::string name)
{
	for(int i = -1; name[i], name[++i];)
		if(name[i] >= 65 && name[i] <= 90)
			name[i] = name[i] + 32;
	return name;
}


AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm *base = NULL;
	std::string type[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	
	name = check_str(name);
	int i = 0;
	while(i < 3)
	{
		if(type[i] == name)
			break;
		i++;
	}
	switch (i)
	{
		case 0:
		{
			base = new RobotomyRequestForm(target);
			break ;
		}	
		case 1:
		{
			base = new PresidentialPardonForm(target);
			break ;
		}
		case 2:
		{
			base = new ShrubberyCreationForm(target);
			break ;
		}
	}
	if(!base)
		std::cout << "This type of form does not exist\n";
	else 
		std::cout << "Inter creates " << name << std::endl;
	return base;
}