/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 06:59:17 by tle-pape          #+#    #+#             */
/*   Updated: 2026/02/06 06:59:18 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main(void)
{
	std::vector<int> vect(20);
	std::vector<int>::iterator iterator;

	for (int i = 0 ; i < 20 ; i++)
		vect[i] = 20 - i;
	for (int i = 0 ; i < 20 ; i++)
		std::cout << vect[i] << std::endl;

	std::cout << std::endl << "Try to find 5 in vect" << std::endl;
	try
	{
		iterator = easyfind<std::vector<int> >(vect, 5);
		std::cout << *iterator << " has been found !" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	std::cout << std::endl << "Replacing " << *iterator << " with 999" << std::endl;
	*iterator = 999;
	for (int i = 0 ; i < 20 ; i++)
		std::cout << vect[i] << std::endl;

	std::cout << std::endl << "Try to find 5 in vect" << std::endl;
	try
	{
		iterator = easyfind<std::vector<int> >(vect, 5);
		std::cout << *iterator << " has been found !" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
