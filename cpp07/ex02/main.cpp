/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 01:14:48 by tle-pape          #+#    #+#             */
/*   Updated: 2026/02/06 01:14:51 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <cstdlib>
#define MAX_VAL 750
int sub_main(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int	main(void)
{
	sub_main();
	int	*a = new int();
	std::cout << "a : " << a << std::endl;
	std::cout << std::endl << std::endl;
	Array<int> nbs(17);
	Array<char> str(17);

	std::cout << "Tests with ints :" << std::endl;
	for (int i = 0 ; i < 17 ; i++)
		nbs[16 - i] = i;
	for (int i = 0 ; i < 17 ; i++)
		std::cout << nbs[i] << std::endl;

	std::cout << std::endl << "Tests with chars :" << std::endl;
	for (int i = 0 ; i < 17 ; i++)
		str[16 - i] = (char)(i + 97);
	for (int i = 0 ; i < 17 ; i++)
		std::cout << str[i] << std::endl;
	delete a;
}
