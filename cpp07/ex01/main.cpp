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

#include "iter.hpp"
#include <cstring>

template <typename T>
void	print_arr_elem(const T &to_print)
{
	std::cout << to_print << std::endl;
}

void	decrement(int &i)
{
	i--;
}

void	ft_toupper(char &c)
{
	if (islower(c))
		c -= 32;
}

int	main(void)
{
	char	str[] = "Bonjour 1!/";
	int		arr[] = {0, 128, -2147483648};

	std::cout << "Test with char * (toupper)  : " << std::endl;
	std::cout << "Before : " << str << std::endl;
	::iter(str, strlen(str), ft_toupper);
	std::cout << "After  : " << str << std::endl << std::endl;

	std::cout << "Test with int * (decrement) : " << std::endl;
	std::cout << "Before : " << arr[0] << ", " 
		<< arr[1] << ", " << arr[2] << std::endl;
	::iter(arr, 3, decrement);
	std::cout << "After  : " << arr[0] << ", " 
		<< arr[1] << ", " << arr[2] << std::endl << std::endl;

	std::cout << "Test with template (print + str)  : " << std::endl;
	::iter(str, strlen(str), print_arr_elem);
	std::cout << "Test with template (print + int)  : " << std::endl;
	::iter(arr, 3, print_arr_elem);
}
