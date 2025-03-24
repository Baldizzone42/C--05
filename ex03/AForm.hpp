/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:54:45 by jormoral          #+#    #+#             */
/*   Updated: 2025/03/24 19:57:54 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool	_signed ;
		const int sign;
		const int _execute;

	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		AForm(std::string name, bool _signed, const int sign, const int _execute);

		const std::string getName() const;
		bool getSigned() const;
		int getGradeToSign()const ;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &other);
		void execute(Bureaucrat const & executor);
		virtual int concrete_execute(Bureaucrat const & executor) const = 0;
		
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
		class ItWasntSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};


std::ostream& operator<<(std::ostream& output, AForm& other);

#endif

