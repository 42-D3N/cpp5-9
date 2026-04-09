/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:26:43 by tle-pape          #+#    #+#             */
/*   Updated: 2026/02/12 15:26:43 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <cstdlib>

# define DEFAULT_CONSTRUCTOR "\e[4m\e[38;2;64;192;255mDefault constructor (BitcoinExchange) called !\e[0m"
# define DEFAULT_COPY_CONTRUCTOR "\e[4m\e[38;2;64;192;255mDefault copy constructor (BitcoinExchange) called !\e[0m"
# define DEFAULT_ASSIGNATION_CONSTRUCTOR "\e[4m\e[38;2;64;192;255mDefault assignation constructor (BitcoinExchange) called !\e[0m"
# define DEFAULT_DESTRUCTOR "\e[4m\e[38;2;64;192;255mDefault destructor (BitcoinExchange) called !\e[0m"
# define PARAMETRIC_CONSTRUCTOR "\e[4m\e[38;2;64;192;255mParametric constructor (BitcoinExchange) called !\e[0m"

class BitcoinExchange
{
private:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	std::ifstream					_db_path;

	std::map<std::string, float>	_main_db;
	std::ifstream					_main_db_path;

public:
	~BitcoinExchange(void);
	BitcoinExchange(char *db_path);

	void	map_fill(void);
	void	calculate(void);
};

#endif
