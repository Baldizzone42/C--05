/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:55:45 by jormoral          #+#    #+#             */
/*   Updated: 2025/03/23 18:11:28 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat St("el firmas", 97);
	Form pilot("titulo de avioneta finladesa", false, 96, 2);
	
	pilot.beSigned(St);
	St.incrementGrade();
	pilot.beSigned(St);
	pilot.beSigned(St);
	std::cout << pilot;
	
	
	return 0;
}