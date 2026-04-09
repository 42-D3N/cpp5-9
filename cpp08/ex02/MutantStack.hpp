/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:02:11 by tle-pape          #+#    #+#             */
/*   Updated: 2026/02/12 13:02:13 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <vector>
# include <stack>
# include <list>
# include <algorithm>

# define DEFAULT_CONSTRUCTOR "Default constructor (MutantStack) called !"
# define DEFAULT_COPY_CONTRUCTOR "Default copy constructor (MutantStack) called !"
# define DEFAULT_ASSIGNATION_CONSTRUCTOR "Default assignation constructor (MutantStack) called !"
# define DEFAULT_DESTRUCTOR "Default destructor (MutantStack) called !"
# define OVERLOAD_CONSTRUCTOR "Overload constructor (MutantStack) called !"

template <typename T>
class MutantStack : public std::stack <T>
{
public:
	MutantStack(void)
	{
		std::cout << DEFAULT_CONSTRUCTOR << std::endl;
	}
	MutantStack(const MutantStack &other)
	{
		std::cout << DEFAULT_COPY_CONTRUCTOR << std::endl;
		this->c = other.c;
	}
	MutantStack &operator=(const MutantStack &other)
	{
		std::cout << DEFAULT_ASSIGNATION_CONSTRUCTOR << std::endl;
		if (this != &other)
		{
			this->c = other.c;
		}
		return (*this);
	}
	~MutantStack(void)
	{
		std::cout << DEFAULT_DESTRUCTOR << std::endl;
	}

	typedef typename std::stack<T>::container_type::iterator		iterator;
	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

	iterator		begin(void)
	{
		return (this->c.begin());
	}
	iterator		end(void)
	{
		return (this->c.end());
	}
	const_iterator	begin(void) const
	{
		return (this->c.begin());
	}
	const_iterator	end(void) const
	{
		return (this->c.end());
	}
};

#endif
