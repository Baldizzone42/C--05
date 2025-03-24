/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:55:45 by jormoral          #+#    #+#             */
/*   Updated: 2025/03/22 20:27:22 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main(void)
{
	Bureaucrat max("paqui", 151);
	Bureaucrat min("robertwido", -2);
	Bureaucrat normal("Paco", 85);

	//como gestiono que hayas burocratas con rangos fuera de (1 - 150)??
	//los creo dandole un rango dentro de lo permitido o los elimino
	std::cout << max << std::endl;
	std::cout << min << std::endl;
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