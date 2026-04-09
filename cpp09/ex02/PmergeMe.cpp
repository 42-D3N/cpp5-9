/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:49:31 by tle-pape          #+#    #+#             */
/*   Updated: 2026/03/16 15:49:31 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	std::cout << DEFAULT_CONSTRUCTOR << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &)
{
	std::cout << DEFAULT_COPY_CONTRUCTOR << std::endl;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &)
{
	std::cout << DEFAULT_ASSIGNATION_CONSTRUCTOR << std::endl;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	std::cout << DEFAULT_DESTRUCTOR << std::endl;
}

static int	jacobsthal(int n) 
{
	return (((pow(2, n) - pow(-1, n)) / 3) * 2);
}

static void	make_pair(std::vector<int> &lst, std::vector<std::pair<int, int> > &pairs)
{
	std::vector<int>	first_of_pairs;

	if (lst.size() < 2)
		return;
	for (size_t i = 0 ; i < lst.size() - 1 ; i += 2)
	{
		if (lst[i] > lst[i + 1])
			pairs.push_back(std::make_pair(lst[i], lst[i + 1]));
		else
			pairs.push_back(std::make_pair(lst[i + 1], lst[i]));
	}

	for (size_t i = 0; i < pairs.size(); i++)
		first_of_pairs.push_back(pairs[i].first);
	if (first_of_pairs.size() > 1)
		PmergeMe::fordJohnsonSort(first_of_pairs);

	for (size_t i = 0 ; i < first_of_pairs.size() ; i++)
	{
		for (size_t j = 0 ; j < pairs.size() ; j++)
		{
			if (first_of_pairs[i] == pairs[j].first)
				std::swap(pairs[j], pairs[i]);
		}
	}
}

static void	insert_sort(std::vector<int> &lst, std::vector<std::pair<int, int> > &pairs)
{
	size_t				js_index = 1, index = 0;
	std::vector<int>	pending, main;

	main.push_back(pairs[0].second);
	main.push_back(pairs[0].first);
	for (size_t i = 1 ; i < pairs.size() ; i++)
	{
		main.push_back(pairs[i].first);
		pending.push_back(pairs[i].second);
	}
	if (lst.size() % 2 == 1)
		pending.push_back(lst.back());
	while (pending.size() > 0)
	{
		index = jacobsthal(js_index) - 1;
		if (index >= pending.size())
			index = pending.size() - 1;
		while (index != std::string::npos)
		{
			std::vector<int>::iterator	it;

			it = std::lower_bound(main.begin(), main.end(), pending[index]);
			main.insert(it, pending[index]);
			pending.erase(pending.begin() + index);
			index--;
		}
		js_index++;
	}
	lst = main;
}

void	PmergeMe::fordJohnsonSort(std::vector<int> &lst)
{
	std::vector<std::pair<int, int> >	pairs;
	if (lst.size() < 2)
		return;

	make_pair(lst, pairs);
	insert_sort(lst, pairs);
}

static void	make_pair(std::deque<int> &lst, std::deque<std::pair<int, int> > &pairs)
{
	std::deque<int>	first_of_pairs;

	if (lst.size() < 2)
		return;
	for (size_t i = 0 ; i < lst.size() - 1 ; i += 2)
	{
		if (lst[i] > lst[i + 1])
			pairs.push_back(std::make_pair(lst[i], lst[i + 1]));
		else
			pairs.push_back(std::make_pair(lst[i + 1], lst[i]));
	}

	for (size_t i = 0; i < pairs.size(); i++)
		first_of_pairs.push_back(pairs[i].first);
	if (first_of_pairs.size() > 1)
		PmergeMe::fordJohnsonSort(first_of_pairs);

	for (size_t i = 0 ; i < first_of_pairs.size() ; i++)
	{
		for (size_t j = 0 ; j < pairs.size() ; j++)
		{
			if (first_of_pairs[i] == pairs[j].first)
				std::swap(pairs[j], pairs[i]);
		}
	}
}

static void	insert_sort(std::deque<int> &lst, std::deque<std::pair<int, int> > &pairs)
{
	size_t			js_index = 1, index = 0;
	std::deque<int>	pending, main;

	main.push_back(pairs[0].second);
	main.push_back(pairs[0].first);
	for (size_t i = 1 ; i < pairs.size() ; i++)
	{
		main.push_back(pairs[i].first);
		pending.push_back(pairs[i].second);
	}
	if (lst.size() % 2 == 1)
		pending.push_back(lst.back());
	while (pending.size() > 0)
	{
		index = jacobsthal(js_index) - 1;
		if (index >= pending.size())
			index = pending.size() - 1;
		while (index != std::string::npos)
		{
			std::deque<int>::iterator	it;

			it = std::lower_bound(main.begin(), main.end(), pending[index]);
			main.insert(it, pending[index]);
			pending.erase(pending.begin() + index);
			index--;
		}
		js_index++;
	}
	lst = main;
}

void	PmergeMe::fordJohnsonSort(std::deque<int> &lst)
{
	std::deque<std::pair<int, int> >	pairs;
	if (lst.size() < 2)
		return;

	make_pair(lst, pairs);
	insert_sort(lst, pairs);
}
