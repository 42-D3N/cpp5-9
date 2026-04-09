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

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "\e[4m\e[38;2;255;0;0mWrong number of arguments, only one RPN expression is needed.\e[0m" << std::endl;
		return (1);
	}
	(void)argv;
	RPN	rpn;
	try
	{
		rpn.setup(argv[1]);
		rpn.calculate();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}
