/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 06:59:37 by tle-pape          #+#    #+#             */
/*   Updated: 2026/02/06 06:59:37 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

# define DEFAULT_CONSTRUCTOR "Default constructor (easyfind) called !"
# define DEFAULT_COPY_CONTRUCTOR "Default copy constructor (easyfind) called !"
# define DEFAULT_ASSIGNATION_CONSTRUCTOR "Default assignation constructor (easyfind) called !"
# define DEFAULT_DESTRUCTOR "Default destructor (easyfind) called !"

class NotFoundException: public std::exception
{
public:
	const char *what() const throw()
	{
		return ("Index not found in container.");
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int to_find)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

#endif
