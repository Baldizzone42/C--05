/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:55:45 by jormoral          #+#    #+#             */
/*   Updated: 2025/05/13 20:12:43 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat Sr("Don", 130);
	Form pilot("titulo de avioneta finladesa", 129, 2);
	
	
	//std::cout << Sr << std::endl;
	//pilot.beSigned(Sr);
	Sr.signForm(pilot);
	Sr.incrementGrade();
	pilot.beSigned(Sr);
	//pilot.beSigned(Sr); 
	std::cout << pilot;
	
	return 0;
}