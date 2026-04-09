/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:01:30 by tle-pape          #+#    #+#             */
/*   Updated: 2026/03/12 11:01:30 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <list>
# include <cstring>
# include <exception>
# include <cstdlib>

# define DEFAULT_CONSTRUCTOR "\e[4m\e[38;2;64;192;255mDefault constructor (RPN) called !\e[0m"
# define DEFAULT_COPY_CONTRUCTOR "\e[4m\e[38;2;64;192;255mDefault copy constructor (RPN) called !\e[0m"
# define DEFAULT_ASSIGNATION_CONSTRUCTOR "\e[4m\e[38;2;64;192;255mDefault assignation constructor (RPN) called !\e[0m"
# define DEFAULT_DESTRUCTOR "\e[4m\e[38;2;64;192;255mDefault destructor (RPN) called !\e[0m"

class	InvalidCharacterException: public std::exception
{
public:
	const char *what() const throw();
};

class	UnexpectedTokenException: public std::exception
{
public:
	const char *what() const throw();
};

class	TooFewOperatorException: public std::exception
{
public:
	const char *what() const throw();
};

class	InvalidNumberException: public std::exception
{
public:
	const char *what() const throw();
};

class	EmptyStringException: public std::exception
{
public:
	const char *what() const throw();
};

class	NoDigitException: public std::exception
{
public:
	const char *what() const throw();
};

class	DivideByZeroException: public std::exception
{
public:
	const char *what() const throw();
};

class	RPN
{
private:
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);

	std::string			_arg;
	std::stack<long, std::list<long> >	_num;

public:
	RPN(void);
	~RPN(void);

	void	setup(char *arg);
	void	calculate();
};

#endif
