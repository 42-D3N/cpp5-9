/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:41:15 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/29 13:41:17 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	std::srand(time(NULL));
	int	random = std::rand() % 3;

	std::cout << "Random object generated : "; 
	switch(random)
	{
		case 0:
			std::cout << "[A]" << std::endl;
			return (new A());
		case 1:
			std::cout << "[B]" << std::endl;
			return (new B());
		case 2:
			std::cout << "[C]" << std::endl;
			return (new C());
		default:
			std::cout << "[A]" << std::endl;
			return (new A());
	}
}

void	identify(Base *p)
{
	std::cout << "identify(Base *p) --> Type : [";
	if (dynamic_cast<A *>(p))
		std::cout << "A]" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B]" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C]" << std::endl;
	else
		std::cout << "Unknown]" << std::endl;
}

void	identify(Base &p)
{
	std::cout << "identify(Base &p) --> Type : [";
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A]" << std::endl;
		return ;
	}
	catch(const std::exception &e){}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B]" << std::endl;
		return ;
	}
	catch(const std::exception &e){}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C]" << std::endl;
		return ;
	}
	catch(const std::exception &e){}
	std::cout << "Unknown]" << std::endl;
}
