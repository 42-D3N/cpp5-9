/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 02:10:17 by tle-pape          #+#    #+#             */
/*   Updated: 2026/02/06 02:10:17 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

# define DEFAULT_CONSTRUCTOR "Default constructor (Array) called !"
# define DEFAULT_COPY_CONTRUCTOR "Default copy constructor (Array) called !"
# define DEFAULT_ASSIGNATION_CONSTRUCTOR "Default assignation constructor (Array) called !"
# define DEFAULT_DESTRUCTOR "Default destructor (Array) called !"
# define OVERLOAD_CONSTRUCTOR "Overload constructor (Array) called !"

template <typename T>
class Array
{
private:
	T				*array;
	unsigned int	len;

public:
	Array(void) :
		len(0)
	{
		std::cout << DEFAULT_CONSTRUCTOR << std::endl;
		this->array = new T[this->len];
	}

	Array(const Array &other) :
		array(NULL), len(other.len)
	{
		std::cout << DEFAULT_COPY_CONTRUCTOR << std::endl;
		*this = other;
	}

	Array &operator=(const Array &other)
	{
		if (this->array)
			delete[] this->array;
		this->len = other.size();
		this->array = new T[this->len];
		for (unsigned int i = 0 ; i < this->len ; i++)
			this->array[i] = other.array[i];
		return (*this);
	}

	Array(unsigned int n) :
		len(n)
	{
		std::cout << OVERLOAD_CONSTRUCTOR << std::endl;
		this->array = new T[this->len];
		for (unsigned int i = 0 ; i < n ; i++)
			this->array[i] = 0;
	}

	~Array(void)
	{
		std::cout << DEFAULT_DESTRUCTOR << std::endl;
		if (this->array)
			delete[] this->array;
	}

	T	&operator[](unsigned int index)
	{
		if (!this->array || index >= len)
			throw Array<T>::InvalidIndexException();
		return (this->array[index]);
	}

	class InvalidIndexException : public std::exception
	{
	public:
		virtual const char	*what() const throw();
	};

	unsigned int	size() const
	{
		return (this->len);
	}
};

template <typename T>
const	char *Array<T>::InvalidIndexException::what() const throw()
{
	return ("Index error : Not in range.");
}

#endif
