/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:09:22 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/30 16:09:23 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void	test_correct_return_if_same_value(int a, int b, std::string c, std::string d)
{
	b = 2;
	int &w = ::min(a, b);
	int &x = ::max(a, b);
	std::cout << "a (" << a << ") = " << &a
		<< std::endl << "b (" << b << ") = " << &b
		<< std::endl << "a_2 (" << w << ") = " << &w
		<< std::endl << "b_2 (" << x << ") = " << &x << std::endl;

	d = "chaine1";
	std::string &y = ::min(c, d);
	std::string &z = ::max(c, d);
	std::cout << "c (" << c << ") = " << &c
		<< std::endl << "d (" << d << ") = " << &d
		<< std::endl << "a_2 (" << y << ") = " << &y
		<< std::endl << "b_2 (" << z << ") = " << &z << std::endl;
}

int	main(void)
{
	int a = 2;
	int b = 3;
	std::string c = "chaine1";
	std::string d = "chaine2";

	// test_correct_return_if_same_value(a, b, c, d);

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	return (0);
}
