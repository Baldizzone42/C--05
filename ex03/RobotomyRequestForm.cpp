/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:12:37 by jormoral          #+#    #+#             */
/*   Updated: 2025/03/24 16:07:41 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm",  72, 45), target("Robotomy") {
	std::cout << "Presidential Form Constructor\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
	std::cout << "Presidential Form Constructor\n";
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "Destructor Robotomy form\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :target(other.target)
{
	std::cout << "Copy Robotomy PForm" << std::endl;
}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "Assignment Robotomy Pardom Form\n";
	if(this != &other)
		*this = other;
	return *this;
}

int RobotomyRequestForm::concrete_execute(Bureaucrat const & executor) const
{
	try
	{
		if(executor.getGrade() > this->getGradeToExecute())
			throw(AForm::GradeTooLowException());
		if (this->getSigned() == false)
			throw(AForm::ItWasntSignedException());
		if(this->getSigned() == true)
		{
			srand(static_cast<unsigned int>(time(0)));
			int n =  rand();

			std::cout << n;
			if(n  % 2 == 0)
				std::cout << this->target << " has been robotomized " << std::endl;
			else
				std::cout << this->target << " he was not lucky enough to be robotized " << std::endl;
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