/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:53:44 by jormoral          #+#    #+#             */
/*   Updated: 2025/03/25 18:04:47 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "RobotomyRequestForm.hpp"
# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"


class Intern
{
	
	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);

		AForm* makeForm(std::string name, std::string target);
	private:
	
};

#endif