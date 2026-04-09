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

#include "PmergeMe.hpp"

template <typename T>
void	display_lst(T &lst)
{
	std::cout << '[';
	for (typename T::iterator	it = lst.begin() ; it < lst.end() ; it++)
	{
		std::cout << *it;
		if (it + 1 != lst.end())
			std::cout << ' ';
		else
			std::cout << ']' << std::endl;
	}
}

static int	parse_arg(int argc, char** argv, std::vector<int> &vec, std::deque<int> &deq)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		for (size_t j = 0; j < arg.size(); j++)
		{
			if (!isdigit(arg[j]))
				return (1);
		}
		long value = std::strtol(arg.c_str(), NULL, 10);
		if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || errno == ERANGE)
			return (1);
		vec.push_back(value);
		deq.push_back(value);
	}
	return (0);
}

static bool	is_sorted(std::vector<int> lst)
{
	for (std::vector<int>::iterator it = lst.begin() ; it != lst.end() - 1 ; it++)
	{
		if (*it > *(it + 1))
			return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	struct timeval vecBefore, vecAfter, deqBefore, deqAfter;
	std::deque<int>		deq;
	std::vector<int>	vec;

	if (argc < 2)
	{
		std::cerr << "Error : Need numbers to sort." << std::endl;
		return (1);
	}
	if (parse_arg(argc, argv, vec, deq))
	{
		std::cerr << "Error : Invalid argument." << std::endl;
		return (1);
	}
	if (is_sorted(vec) == true)
	{
		display_lst(vec);
		std::cout << "Info : Sequence given is already sorted. Abort." << std::endl;
		return (0);
	}
	std::cout << "Before : ";
	display_lst(vec);

	gettimeofday(&vecBefore, NULL);
	PmergeMe::fordJohnsonSort(vec);
	gettimeofday(&vecAfter, NULL);
	gettimeofday(&deqBefore, NULL);
	PmergeMe::fordJohnsonSort(deq);
	gettimeofday(&deqAfter, NULL);

	std::cout << "After  : ";
	display_lst(vec);

	std::cout	<< "Time to process a range of " << vec.size()
				<< " elements with [std::vector] : " << std::fixed << std::setprecision(3)
				<< static_cast<double>((vecAfter.tv_sec - vecBefore.tv_sec) * 1000000 + (vecAfter.tv_usec - vecBefore.tv_usec)) / 1000
				<< " milliseconds" << std::endl
				<< "Time to process a range of " << deq.size()
				<< " elements with [std::deque]  : " << std::fixed << std::setprecision(3)
				<< static_cast<double>((deqAfter.tv_sec - deqBefore.tv_sec) * 1000000 + (deqAfter.tv_usec - deqBefore.tv_usec)) / 1000
				<< " milliseconds" << std::endl;
}
