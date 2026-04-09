/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:26:26 by tle-pape          #+#    #+#             */
/*   Updated: 2026/02/12 15:26:27 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>

void	main_error(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error : wrong number of arguments." << std::endl;
		exit(1);
	}

	std::ifstream	try_open("data.csv");
	if (!try_open.is_open())
	{
		std::cerr << "Error : Missing \"data.csv\" database." << std::endl;
		exit(1);
	}
	else
		try_open.close();
	try_open.open(argv[1]);
	if (!try_open.is_open())
	{
		std::cerr << "Error : Unable to open [" << argv[1] << "]." << std::endl;
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	main_error(argc, argv);
	BitcoinExchange	btc(argv[1]);
	btc.calculate();
}
