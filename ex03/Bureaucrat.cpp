/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:57:37 by jormoral          #+#    #+#             */
/*   Updated: 2025/03/24 18:25:48 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"


Bureaucrat::Bureaucrat() : name("esbirro"), grade(150){
	std::cout << "Default Bureaucrat\n";
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	std::cout << "Named/Graded Bureaucrat\n";
	try
	{
		if (this->grade > 150)
		{
			this->grade = 150;
			throw(Bureaucrat::GradeTooLowException());
		}
		else if (this->grade < 1)
		{
			this->grade = 150;
			throw(Bureaucrat::GradeTooHighException());
		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Destructor Bureaucrat\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	std::cout << "Copy Bureaucrat" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Assignment Bureaucrat\n";
	if(this != &other)
		*this = other;
	return *this;
}

void Bureaucrat::signForm(AForm &other){
	other.beSigned(*this);
}


int Bureaucrat::getGrade() const
{
	return this->grade;
}

const std::string Bureaucrat::getName() const
{
	return this->name;
}

void Bureaucrat::decrementGrade(void)
{
	try
	{
		if(this->grade >= 150)
			throw (Bureaucrat::GradeTooLowException());
		this->grade++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}


void Bureaucrat::incrementGrade(void)
{
	try
	{
		if(this->grade <= 1)
			throw(Bureaucrat::GradeTooHighException());
		this->grade--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	form.concrete_execute(*this);
}

const char *Bureaucrat::GradeTooLowExecute::what() const throw()
{
	return "Grade too low\n";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "You are at the highest grade as a bureaucrat\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "You are at the lowest grade as a bureaucrat\n";
}

std::string IntToString(int i)
{
	std::stringstream temp;
	temp << i;
	return temp.str();
}

std::ostream& operator<<(std::ostream& output, Bureaucrat& other)
{
	output << other.getName() + ", bureaucrat grade " + IntToString(other.getGrade());
	return output;
}
