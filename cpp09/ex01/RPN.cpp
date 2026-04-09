/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:01:30 by tle-pape          #+#    #+#             */
/*   Updated: 2026/03/12 11:01:30 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	std::cout << DEFAULT_CONSTRUCTOR << std::endl;
}

RPN::RPN(const RPN &)
{
	std::cout << DEFAULT_COPY_CONTRUCTOR << std::endl;
}
RPN	&RPN::operator=(const RPN &)
{
	std::cout << DEFAULT_ASSIGNATION_CONSTRUCTOR << std::endl;
	return (*this);
}

RPN::~RPN(void)
{
	std::cout << DEFAULT_DESTRUCTOR << std::endl;
}

static void	parse_arg(char *arg)
{
	size_t		digit_count = 0,
				operator_count = 0,
				len = strlen(arg);
	std::string	charset("0123456789 +-*/");
	bool		err = false;

	if (len == 0)
		throw EmptyStringException();
	for (size_t i = 0 ; i < len ; i++)
	{
		if (charset.find(arg[i]) == std::string::npos)
		{
			if (err == false)
				std::cerr << arg << std::endl << "\e[38;2;255;0;0m" << std::string(i, ' ') << "\e[1m\e[53m^\e[0m";
			else
				std::cerr << "\e[1m\e[53m^\e[0m";
			err = true;
		}
		else if (err == true)
			std::cerr << ' ';
	}
	if (err == true)
	{
		std::cerr << std::endl;
		throw InvalidCharacterException();
	}
	else
	{
		for (size_t i = 0 ; i < len ; i++)
		{
			if (isdigit(arg[i]) && arg[i + 1] && isdigit(arg[i + 1]))
			{
				std::cerr << arg << std::endl << std::string(i, ' ') << "\e[1m\e[53m^\e[0m";
				while (isdigit(arg[++i]))
					std::cerr << "\e[1m\e[53m~\e[0m";
				std::cerr << std::endl;
				throw InvalidNumberException();
			}
			else if (isdigit(arg[i]))
				digit_count++;
			else if (arg[i] !=  ' ')
				operator_count++;
			if (charset.find(arg[i]) > 10 && charset.find(arg[i] <= 14))
			{
				if (operator_count + 1 > digit_count)
				{
					if (err == false)
					{
						std::cerr << arg << std::endl << std::string(i, ' ') << "\e[1m\e[53m^\e[0m";
						err = true;
					}
					else
						std::cerr << "\e[1m\e[53m^\e[0m";
					operator_count--;
				}
				else if (err == true)
					std::cerr << ' ';
			}
			else if (err == true)
				std::cerr << ' ';
		}
		if (err == true)
		{
			std::cerr << std::endl;
			throw UnexpectedTokenException();
		}
	}
	if (digit_count > operator_count + 1)
	{
		std::cerr << arg << std::endl << std::string(len, ' ') << "\e[1m\e[53m^\e[0m" << std::endl;
		throw TooFewOperatorException();
	}
	if (digit_count == 0)
		throw NoDigitException();
}

void	RPN::setup(char *arg)
{
	parse_arg(arg);
	_arg = std::string(arg);
}

void	RPN::calculate()
{
	long	res = 0, tmp = 0;

	if (_arg.length() == 0)
	{
		std::cerr << "\e[38;2;255;0;0m\e[4mInternal error found : No argument stored.\e[0m" << std::endl;
		return ;
	}
	for (size_t i = 0 ; i < _arg.length() ; i++)
	{
		if (_arg[i] == ' ')
			continue;
		if (isdigit(_arg[i]))
			_num.push(strtol(&_arg[i], NULL, 10));
		else
		{
			tmp = _num.top();
			_num.pop();
			if (_arg[i] == '+')
				res = _num.top() + tmp;
			else if (_arg[i] == '-')
				res = _num.top() - tmp;
			else if (_arg[i] == '*')
				res = _num.top() * tmp;
			else if (_arg[i] == '/')
			{
				if (tmp == 0)
					throw DivideByZeroException();
				res = _num.top() / tmp;
			}
			_num.pop();
			_num.push(res);
		}
	}
	std::cout << "Result : [" << _num.top() << "]" << std::endl;
}

const char *InvalidCharacterException::what() const throw()
{
	return ("\e[38;2;255;0;0m\e[4mError : Invalid character found.\e[0m");
}

const char *UnexpectedTokenException::what() const throw()
{
	return ("\e[38;2;255;0;0m\e[4mError : Unexpected token.\e[0m");
}

const char *TooFewOperatorException::what() const throw()
{
	return ("\e[38;2;255;0;0m\e[4mError : Too few operators.\e[0m");
}

const char *InvalidNumberException::what() const throw()
{
	return ("\e[38;2;255;0;0m\e[4mError : Invalid number.\e[0m");
}

const char *EmptyStringException::what() const throw()
{
	return ("\e[38;2;255;0;0m\e[4mError : Empty string.\e[0m");
}

const char *NoDigitException::what() const throw()
{
	return ("\e[38;2;255;0;0m\e[4mError : No operator or digit.\e[0m");
}

const char *DivideByZeroException::what() const throw()
{
	return ("\e[38;2;255;0;0m\e[4mError : Division par 0 impossible.\e[0m");
}
