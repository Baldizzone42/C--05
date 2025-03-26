/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:54:45 by jormoral          #+#    #+#             */
/*   Updated: 2025/03/26 16:22:48 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool	_signed ;
		const int sign;
		const int execute;

	public:
		Form();
		~Form();
		Form(const Form &other);
		Form& operator=(const Form &other);
		Form(std::string name, const int sign, const int execute);

		const std::string getName();
		bool getSigned();
		int getGradeToSign()const ;
		int getGradeToExecute();
		void beSigned(Bureaucrat &other);
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class ItWasSignedException : public std::exception
		{
			public:
				const char* what() const throw();	
		};
};


std::ostream& operator<<(std::ostream& output, Form& other);

#endif

