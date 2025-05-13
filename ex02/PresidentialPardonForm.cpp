/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:12:37 by jormoral          #+#    #+#             */
/*   Updated: 2025/05/13 20:38:33 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardomForm", 25, 5), target("(null)") 
{
	std::cout << "Presidential Form Constructor\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardomForm",  25, 5), target(target) {
	std::cout << "Presidential Form Constructor\n";
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "Destructor Presidential form\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :target(other.target)
{
	std::cout << "Copy Presidential Pardom Form" << std::endl;
}


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "Assignment Presidential Pardom Form\n";
	if(this != &other)
		*this = other;
	return *this;
}

int PresidentialPardonForm::concrete_execute(Bureaucrat const & executor) const
{
	try
	{
		if(executor.getGrade() > this->getGradeToExecute())
			throw(AForm::GradeTooLowException());
		if (this->getSigned() == false)
			throw(AForm::ItWasntSignedException());
		if(this->getSigned() == true)
		{
			std::cout << this->target << " has been pardoned by Zaphod Beeblebrox. " << std::endl;
			return(0);
		}
	}
	catch(std::exception & e)
	{
		std::cerr << e.what();
		return(1);
	}
	return 0;
}