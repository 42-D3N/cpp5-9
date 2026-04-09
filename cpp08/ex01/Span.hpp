/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 09:31:32 by tle-pape          #+#    #+#             */
/*   Updated: 2026/02/06 09:31:32 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

# define DEFAULT_CONSTRUCTOR "Default constructor (Span) called !"
# define DEFAULT_COPY_CONTRUCTOR "Default copy constructor (Span) called !"
# define DEFAULT_ASSIGNATION_CONSTRUCTOR "Default assignation constructor (Span) called !"
# define DEFAULT_DESTRUCTOR "Default destructor (Span) called !"
# define OVERLOAD_CONSTRUCTOR "Overload constructor (Span) called !"

class ArrayFullException: public std::exception
{
public:
	const char *what() const throw()
	{
		return ("Can't add new number, not enough space to add number(s).");
	}
};

class CantFindSpanException: public std::exception
{
public:
	const char *what() const throw()
	{
		return ("Can't find span : No or only one number stored.");
	}
};

class Span
{
private:
	Span(void);
	unsigned int		size;
	unsigned int		actual_size;
	std::vector<int>	vect;

public:
	Span(unsigned int len);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span(void);

	std::vector<int> const	getArray(void);
	void					addNumber(int new_number);
	void					addNumber(std::vector<int> const new_numbers);
	unsigned int			longestSpan(void);
	unsigned int			shortestSpan(void);
};

#endif
