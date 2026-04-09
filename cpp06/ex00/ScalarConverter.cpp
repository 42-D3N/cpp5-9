/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:11:05 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/26 11:11:05 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cstdio>

ScalarConverter::ScalarConverter(void)
{
	std::cout << DEFAULT_CONSTRUCTOR << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << DEFAULT_COPY_CONTRUCTOR << std::endl;
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << DEFAULT_ASSIGNATION_CONSTRUCTOR << std::endl;
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << DEFAULT_DESTRUCTOR << std::endl;
}

static char	float_or_double(std::string to_convert)
{
	int	i = 0;

	if (to_convert.find('.') != to_convert.rfind('.') 
		|| to_convert.find('f') != to_convert.rfind('f')
		|| to_convert.rfind('f') < to_convert.length() - 1
		|| (!isdigit(to_convert[i]) && to_convert[i] != '-' /*&& to_convert[i] != '.'*/)) // Uncomment to handle [.2f]
		return (-1);
	if (to_convert[i] == '-')
		i++;
	while (to_convert[i])
	{
		if (!isdigit(to_convert[i])
			&& to_convert[i] != 'f'
			&& to_convert[i] != '.')
			return (-1);
		i++;
	}
	if (to_convert.find('f') < to_convert.length())
	{
		if (to_convert.find('.') + 1 == to_convert.find('f')) // Remove this check to handle [2.f]
			return (-1);
		strtof(to_convert.c_str(), NULL);
		if (errno == ERANGE)
			return (-1);
		return (2);
	}
	if (to_convert.find('.') == to_convert.length() - 1) // Remove this check to handle [1.]
		return (-1);
	strtod(to_convert.c_str(), NULL);
	if (errno == ERANGE)
		return (-1);
	return (3);
}

static char	which_literal_type(std::string to_convert)
{
	int i = 0;

	if (to_convert.length() == 1 && isascii(to_convert[0]) && !isdigit(to_convert[0]))
		return (0);
	if (to_convert.find('.') < to_convert.length())
		return (float_or_double(to_convert));
	while (to_convert[i])
	{
		if (i == 0 && to_convert[i] == '-')
			i++;
		else if (!isdigit(to_convert[i]))
			return (-1);
		i++;
	}
	if ((to_convert[0] != '-' && atoi(to_convert.c_str()) < 0)
		|| (to_convert[0] == '-' && atoi(to_convert.c_str()) >= 0))
		return (-1);
	return (1);
}

static char	which_type(std::string to_convert)
{
	if (to_convert == "")
		return (-1);
	else if (to_convert == "nan" || to_convert == "nanf"
			|| to_convert == "-inf" || to_convert == "+inf"
			|| to_convert == "-inff" || to_convert == "+inff")
		return (4);
	else
		return (which_literal_type(to_convert));
}

static void	fromChar(const std::string to_convert)
{
	char	c = to_convert[0];

	std::cout << "Original (char) : [" << to_convert << "]" << std::endl;
	if (!isprint(c))
		std::cout << "Char   : Non printable" << std::endl;
	else
		std::cout << "Char   : '" << c << "'" << std::endl;

	std::cout << "Int    : " << static_cast<int>(c) << std::endl;
	std::cout << "Float  : " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "Double : " << static_cast<double>(c) << ".0" << std::endl;
}

static void	fromInt(const std::string to_convert)
{
	int	i = atoi(to_convert.c_str());

	std::cout << "Original (int) : [" << to_convert << "]" << std::endl;
	if (i < 0 || i > 127)
		std::cout << "Char   : Overflow (OoR)" << std::endl;
	else if (!isprint(static_cast<char>(i)))
		std::cout << "Char   : Non printable" << std::endl;
	else
		std::cout << "Char   : '" << static_cast<char>(i) << "'" << std::endl;

	std::cout << "Int    : " << i << std::endl;
	std::cout << "Float  : " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "Double : " << static_cast<double>(i) << ".0" << std::endl;
}

static void	fromFloat(const std::string to_convert)
{
	float	f = atof(to_convert.c_str());
	float	useless = 0;

	std::cout << "Original (float) : [" << to_convert << "]" << std::endl;
	if (f < 0 || f > 127)
		std::cout << "Char   : Overflow (OoR)" << std::endl;
	else if (!isprint(static_cast<char>(f)))
		std::cout << "Char   : Non printable" << std::endl;
	else
		std::cout << "Char   : '" << static_cast<char>(f) << "'" << std::endl;

	std::cout << "Int    : " << static_cast<int>(f) << std::endl;

	std::cout << "Float  : " << f;
	if (modff(f, &useless) == 0)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	std::cout << "Double : " << static_cast<double>(f);

	if (modff(f, &useless) == 0)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

static void	fromDouble(const std::string to_convert)
{
	double	d = strtod(to_convert.c_str(), NULL);
	double	useless = 0;

	std::cout << "Original (double) : [" << to_convert << "]" << std::endl;
	if (d < 0 || d > 127)
		std::cout << "Char   : Overflow (OoR)" << std::endl;
	else if (!isprint(static_cast<char>(d)))
		std::cout << "Char   : Non printable" << std::endl;
	else
		std::cout << "Char   : '" << static_cast<char>(d) << "'" << std::endl;

	std::cout << "Int    : " << static_cast<int>(d) << std::endl;

	std::cout << "Float  : " << static_cast<float>(d);
	if (modf(d, &useless) == 0)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;

	std::cout << "Double : " << d;
	if (modf(d, &useless) == 0)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

static void	fromSpecial(const std::string to_convert)
{
	if (to_convert == "nan" || to_convert == "+inf" || to_convert == "-inf")
	{
		std::cout << "Original (double) : [" << to_convert << "]" << std::endl;
		double	d = strtod(to_convert.c_str(), NULL);

		std::cout << "<Double> (" << to_convert << ") to <Char> is impossible." << std::endl;
		std::cout << "<Double> (" << to_convert << ") to <Int> is impossible." << std::endl;
		std::cout << "Float  : " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "Double : " << d << std::endl;
	}
	else if (to_convert == "nanf" || to_convert == "+inff" || to_convert == "-inff")
	{
		std::cout << "Original (float) : [" << to_convert << "]" << std::endl;
		float	f = strtof(to_convert.c_str(), NULL);

		std::cout << "<Float> (" << to_convert << ") to <Char> is impossible." << std::endl;
		std::cout << "<Float> (" << to_convert << ") to <Int> is impossible." << std::endl;
		std::cout << "Float  : " << f << "f" << std::endl;
		std::cout << "Double : " << static_cast<double>(f) << std::endl;
	}
}

void	ScalarConverter::convert(std::string to_convert)
{
	char	c;
	void	(*func[])(const std::string to_convert) =
	{
		&fromChar,
		&fromInt,
		&fromFloat,
		&fromDouble
	};

	c = which_type(to_convert);
	if (c < 0)
	{
		std::cout << INVALID << to_convert << ")" << std::endl;
		std::cout << ACCEPTED << std::endl;
		return ;
	}
	if (c < 4)
		func[(int)c](to_convert);
	else
		fromSpecial(to_convert);
}
