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

#include "MutantStack.hpp"

void	subject_tests(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

void	subject_tests_list(void)
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	own_tests(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int> copy(mstack);
	MutantStack<int> assign;
	assign = mstack;

	std::cout << "List : " << std::endl;
	while (!mstack.empty())
	{
		std::cout << mstack.top() << std::endl;
		mstack.pop();
	}

	std::cout << "Copy list :" << std::endl;
	while (!copy.empty())
	{
		std::cout << copy.top() << std::endl;
		copy.pop();
	}

	std::cout << "Assign list :" << std::endl;
	while (!assign.empty())
	{
		std::cout << assign.top() << std::endl;
		assign.pop();
	}
}

int	main(void)
{
	subject_tests();
	std::cout << std::endl << std::endl;
	subject_tests_list();
	std::cout << std::endl << std::endl;
	own_tests();
}
