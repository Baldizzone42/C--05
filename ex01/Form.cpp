/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:56:15 by jormoral          #+#    #+#             */
/*   Updated: 2025/03/26 16:22:41 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("titulitis"), _signed(false), sign(150), execute(150)
{
	std::cout << "Default Form" << std::endl;
}

Form::~Form(){
	std::cout << "Destructor Form" << std::endl;
}

Form::Form(const Form &other) : name(other.name), _signed(other._signed), sign(other.sign), execute(other.execute)
{
	std::cout << "Copy Form" << std::endl;
}

Form& Form::operator=(const Form &other)
{
	if(this != &other)
		*this = other;
	return *this;
}

Form::Form(std::string name, const int sign, const int execute)
: name(name), sign(sign), execute(execute)
{
	this->_signed = false;
	if(this->_signed == true)
	{
		std::cout << "this Form " << this->getName() << " it's signed\n";
		return ;
	}
	try
	{
		if(this->sign > 150 || this->execute > 150)
			throw (Form::GradeTooLowException());
		if(this->sign < 1 || this->execute < 1)
			throw (Form::GradeTooHighException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}

const std::string Form::getName(){
	return this->name;
}

bool Form::getSigned(){
	return this->_signed;
}

int Form::getGradeToSign() const{
	return this->sign;
}

int Form::getGradeToExecute(){
	return this->execute;
}

void Form::beSigned(Bureaucrat& other)
{
	try
	{
		if(this->_signed == true)
		{
			std::cerr << other.getName() << " couldn't sign " << this->name << " because ";
			throw (Form::ItWasSignedException());
		}
		else if(other.getGrade() > this->getGradeToSign())
		{
			std::cerr << other.getName() << " couldn't sign " << this->name << " because ";
			throw(Form::GradeTooLowException());
		}
		this->_signed = true;
		std::cout << other.getName() << " signed " + this->getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}

const char *Form::ItWasSignedException::what() const throw()
{
	return "it's already signed\n";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade too High!\n";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade too Low!\n";
}

std::ostream& operator<<(std::ostream& output, Form& other)
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