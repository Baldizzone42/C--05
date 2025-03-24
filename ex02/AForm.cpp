/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:56:15 by jormoral          #+#    #+#             */
/*   Updated: 2025/03/24 15:56:41 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("titulitis"), _signed(false), sign(150), _execute(150)
{
	std::cout << "Default Form" << std::endl;
}

AForm::~AForm(){
	std::cout << "Destructor Form" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.name), _signed(other._signed), sign(other.sign), _execute(other._execute)
{
	std::cout << "Copy Form" << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
	if(this != &other)
		*this = other;
	return *this;
}

AForm::AForm(std::string name, bool _signed, const int sign, const int execute)
: name(name), _signed(_signed), sign(sign), _execute(execute)
{
	if(this->_signed == true)
	{
		std::cout << "this Form " << this->getName() << " it's signed\n";
		return ;
	}
	try
	{
		if(this->sign > 150 || this->_execute > 150)
			throw (AForm::GradeTooLowException());
		if(this->sign < 1 || this->_execute < 1)
			throw (AForm::GradeTooHighException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}

const std::string AForm::getName() const{
	return this->name;
}

bool AForm::getSigned() const{
	return this->_signed;
}

int AForm::getGradeToSign() const{
	return this->sign;
}

int AForm::getGradeToExecute() const{
	return this->_execute;
}

void AForm::beSigned(Bureaucrat& other)
{
	try
	{
		if(this->_signed == true)
		{
			std::cerr << other.getName() << " couldn't sign " << this->name << " because ";
			throw (AForm::ItWasSignedException());
		}
		else if(other.getGrade() > this->getGradeToSign())
		{
			std::cerr << other.getName() << " couldn't sign " << this->name << " because ";
			throw(AForm::GradeTooLowException());
		}
		this->_signed = true;
		std::cout << other.getName() << " signed " + this->getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}

const char *AForm::ItWasntSignedException::what() const throw()
{
	return "has not been signed\n";
}

const char *AForm::ItWasSignedException::what() const throw()
{
	return "it's already signed\n";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade too High!\n";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "grade too Low!\n";
}


void AForm::execute(Bureaucrat const & executor) 
{
	executor.executeForm(*this);
}

std::ostream& operator<<(std::ostream& output, AForm& other)
{
	output << "Form name: " << other.getName() << std::endl;
	if(other.getSigned() == true)
		output << "It was signed\n";
	else
		output << "Could not be signed\n";
	output << "Sign Grade " << other.getGradeToSign() << std::endl;
	output << "Execute Grade " << other.getGradeToExecute() << std::endl;
	return output;
}