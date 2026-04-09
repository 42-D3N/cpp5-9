/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:11:05 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/26 11:11:05 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cmath>
# include <limits>
# include <errno.h>

# define DEFAULT_CONSTRUCTOR "Default constructor (ScalarConverter) called !"
# define DEFAULT_COPY_CONTRUCTOR "Default copy constructor (ScalarConverter) called !"
# define DEFAULT_ASSIGNATION_CONSTRUCTOR "Default assignation constructor (ScalarConverter) called !"
# define DEFAULT_DESTRUCTOR "Default destructor (ScalarConverter) called !"

# define INVALID "Error : Invalid input ("
# define ACCEPTED "Accepted inputs :\n- Type    : char, int, double, float.\n\
- Special : -inff, +inff, nanf, -inf, +inf, nan."

class ScalarConverter
{
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter(void);

public:
	static void	convert(std::string to_convert);
};

#endif
