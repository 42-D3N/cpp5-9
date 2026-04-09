/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 09:31:38 by tle-pape          #+#    #+#             */
/*   Updated: 2026/02/06 09:31:39 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	display_array(std::vector<int>	test)
{
	std::cout << "[";
	for (unsigned int i = 0 ; i < test.size() ; i++)
	{
		std::cout << test[i];
		if (i + 1 < test.size())
			std::cout << " ; ";
	}
	std::cout << "]" << std::endl;
}

void	subject_tests(void)
{
	Span	array_sub = Span(5);

	array_sub.addNumber(6);
	array_sub.addNumber(3);
	array_sub.addNumber(17);
	array_sub.addNumber(9);
	array_sub.addNumber(11);

	display_array(array_sub.getArray());
	std::cout << array_sub.shortestSpan() << std::endl;
	std::cout << array_sub.longestSpan() << std::endl;
}

void	span_n_array_full(void)
{
	Span	array(13);

	display_array(array.getArray());
	array.addNumber(13);
	display_array(array.getArray());
	array.addNumber(1);
	array.addNumber(12);
	array.addNumber(2);
	array.addNumber(11);
	array.addNumber(3);
	array.addNumber(10);
	array.addNumber(4);
	array.addNumber(9);
	array.addNumber(5);
	array.addNumber(8);
	array.addNumber(6);
	try
	{
		array.addNumber(7);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		array.addNumber(14);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	display_array(array.getArray());
	std::cout << array.shortestSpan() << std::endl;
	std::cout << array.longestSpan() << std::endl;
}

void	span_with_no_or_one_number(void)
{
	Span	arr(10);

	try
	{
		std::cout << arr.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	arr.addNumber(1);
	try
	{
		std::cout << arr.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	arr.addNumber(1);
	std::cout << arr.shortestSpan() << std::endl;
	std::cout << arr.longestSpan() << std::endl;
	arr.addNumber(1);
	arr.addNumber(1);
	arr.addNumber(1);
	arr.addNumber(2);
	arr.addNumber(888888);
	arr.addNumber(2);
	arr.addNumber(2);
	arr.addNumber(1);
	std::cout << arr.shortestSpan() << std::endl;
	std::cout << arr.longestSpan() << std::endl;
}

void	add_array_in_Span(void)
{
	Span				arrey(20000);
	std::vector<int>	to_insert(19999);

	std::fill(to_insert.begin(), to_insert.end(), 6);
	arrey.addNumber(1);
	arrey.addNumber(to_insert);
	std::cout << arrey.shortestSpan() << std::endl;
	std::cout << arrey.longestSpan() << std::endl;
	try
	{
		arrey.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		arrey.addNumber(to_insert);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	subject_tests();
	std::cout << std::endl << std::endl;
	span_n_array_full();
	std::cout << std::endl << std::endl;
	span_with_no_or_one_number();
	std::cout << std::endl << std::endl;
	add_array_in_Span();
}
