/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:55:45 by jormoral          #+#    #+#             */
/*   Updated: 2025/05/13 19:15:49 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat max("paquillo", 1);
	std::cout << max << std::endl;
	Bureaucrat test("random", 3);
	test.incrementGrade();
	std::cout << test << std::endl;
	max.decrementGrade();
	std::cout << max.getGrade() << std::endl;
	Bureaucrat normal("Paco", 85);

	std::cout << max << std::endl;
	std::cout << normal << std::endl;
	
	Bureaucrat top("TOP", 1);
	std::cout << top << std::endl;
	top.incrementGrade();
	std::cout << top << std::endl; 

	Bureaucrat lowest("LOW", 150);
	std::cout << lowest << std::endl;
	lowest.decrementGrade();
	std::cout << lowest << std::endl; 
	return 0;
}