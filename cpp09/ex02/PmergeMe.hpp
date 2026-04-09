/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:49:31 by tle-pape          #+#    #+#             */
/*   Updated: 2026/03/16 15:49:31 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <iostream>
# include <algorithm>
# include <cmath>
# include <sys/time.h>
# include <iomanip>
# include <limits>
# include <errno.h>

# define DEFAULT_CONSTRUCTOR "\e[4m\e[38;2;64;192;255mDefault constructor (PmergeMe) called !\e[0m"
# define DEFAULT_COPY_CONTRUCTOR "\e[4m\e[38;2;64;192;255mDefault copy constructor (PmergeMe) called !\e[0m"
# define DEFAULT_ASSIGNATION_CONSTRUCTOR "\e[4m\e[38;2;64;192;255mDefault assignation constructor (PmergeMe) called !\e[0m"
# define DEFAULT_DESTRUCTOR "\e[4m\e[38;2;64;192;255mDefault destructor (PmergeMe) called !\e[0m"

class PmergeMe
{
private:
	PmergeMe(void);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe(void);

public:
	static void	fordJohnsonSort(std::deque<int> &lst);
	static void	fordJohnsonSort(std::vector<int> &lst);
};

#endif
