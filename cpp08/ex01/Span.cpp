/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 09:31:32 by tle-pape          #+#    #+#             */
/*   Updated: 2026/02/06 09:31:32 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) :
	size(0), actual_size(0)
{
	std::cout << DEFAULT_CONSTRUCTOR << std::endl;
}

Span::Span(const Span &other) :
	size(other.size), actual_size(other.actual_size), vect(other.vect)
{
	std::cout << DEFAULT_COPY_CONTRUCTOR << std::endl;
}

Span &Span::operator=(const Span &other)
{
	std::cout << DEFAULT_ASSIGNATION_CONSTRUCTOR << std::endl;
	if (this != &other)
	{
		this->size = other.size;
		this->actual_size = other.actual_size;
		this->vect.insert(this->vect.begin(), other.vect.begin(), other.vect.end());
	}
	return (*this);
}

Span::~Span(void)
{
	std::cout << DEFAULT_DESTRUCTOR << std::endl;
}

Span::Span(unsigned int len) :
	size(len), actual_size(0)
{
	std::cout << OVERLOAD_CONSTRUCTOR << std::endl;
}

std::vector<int> const	Span::getArray(void)
{
	return (this->vect);
}

void	Span::addNumber(int new_number)
{
	if (actual_size >= size)
		throw ArrayFullException();
	else
	{
		vect.push_back(new_number);
		actual_size++;
	}
}

void	Span::addNumber(std::vector<int> const new_numbers)
{
	if (actual_size >= size && actual_size + new_numbers.size() > size)
		throw ArrayFullException();
	else
	{
		actual_size += new_numbers.size();
		vect.insert(vect.begin(), new_numbers.begin(), new_numbers.end());
	}
}

unsigned int	Span::longestSpan(void)
{
	unsigned int	min = 0, max = 0;

	if (actual_size < 2)
		throw CantFindSpanException();

	min = *std::min_element(this->vect.begin(), this->vect.end());
	max = *std::max_element(this->vect.begin(), this->vect.end());

	return (max - min);
}

unsigned int	Span::shortestSpan(void)
{
	unsigned int	span = -1;

	if (actual_size < 2)
		throw CantFindSpanException();

	std::sort(vect.begin(), vect.end());
	for (unsigned int i = 1 ; i < actual_size && span != 0 ; i++)
	{
		if ((unsigned int)vect[i] - vect[i - 1] < span)
			span = vect[i] - vect[i - 1];
	}
	return (span);
}
