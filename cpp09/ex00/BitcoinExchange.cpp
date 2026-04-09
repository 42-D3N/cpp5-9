/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:26:43 by tle-pape          #+#    #+#             */
/*   Updated: 2026/02/12 15:26:43 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static void	search_and_display(std::map<std::string, float> main_db, std::string date, float value);
static bool	value_validation(std::string value);
static bool	date_validation(std::string date);

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << DEFAULT_CONSTRUCTOR << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &)
{
	std::cout << DEFAULT_COPY_CONTRUCTOR << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &)
{
	std::cout << DEFAULT_ASSIGNATION_CONSTRUCTOR << std::endl;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	if (_db_path.is_open())
		_db_path.close();
	if (_main_db_path.is_open())
		_main_db_path.close();
	_main_db.clear();
	std::cout << DEFAULT_DESTRUCTOR << std::endl;
}

BitcoinExchange::BitcoinExchange(char *db_path)
{
	std::cout << PARAMETRIC_CONSTRUCTOR << std::endl;
	_main_db_path.open("data.csv");
	std::cout << "[data.csv] opened successfully." << std::endl;
	_db_path.open(db_path);
	std::cout << "[" << db_path << "] opened successfully." << std::endl;
	map_fill();
}

void	BitcoinExchange::map_fill(void)
{
	std::string	line, date, value;
	size_t		pipe_pos;

	getline(_main_db_path, line);
	while (getline(_main_db_path, line))
	{
		pipe_pos = line.find(",");
		if (pipe_pos != line.rfind(",") || pipe_pos == std::string::npos)
		{
			std::cerr << "Error: [data.csv] line error : [" << line << "]. Skipping..." << std::endl;
			continue;
		}
		date = line.substr(0, pipe_pos);
		value = line.substr(pipe_pos + 1, line.length());
		_main_db.insert(std::make_pair(date, strtof(value.c_str(), NULL)));
	}
}

void	BitcoinExchange::calculate(void)
{
	std::string	line, date, value;
	size_t		pipe_pos, curr_line;

	curr_line = 0;
	getline(_db_path, line);
	if (line.length() == 0)
	{
		std::cerr << "Input file is empty." << std::endl;
		return ;
	}
	while (getline(_db_path, line))
	{
		pipe_pos = line.find("|");
		if (pipe_pos != line.rfind("|") || pipe_pos == std::string::npos || pipe_pos + 3 > line.length())
		{
			std::cerr << "Error: bad input : [" << line << "]" << std::endl;
			continue;
		}
		date = line.substr(0, pipe_pos - 1);
		if (!date_validation(date))
			continue;
		value = line.substr(pipe_pos + 2, line.length());
		if (!value_validation(value))
			continue;
		search_and_display(_main_db, date, strtof(value.c_str(), NULL));
		curr_line++;
	}
}

static bool	is_real_date(std::string date)
{
	bool	is_bissextile = false;
	int		year, month, day;
	size_t	first_hyphen, second_hyphen;

	first_hyphen = date.find('-');
	second_hyphen = date.rfind('-');
	year = atoi(date.substr(0, first_hyphen).c_str());
	month = atoi(date.substr(first_hyphen + 1, second_hyphen - first_hyphen - 1).c_str());
	day = atoi(date.substr(second_hyphen + 1, date.length()).c_str());

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		is_bissextile = true;
	if (month > 12 || month < 1)
	{
		std::cerr << "Month is not valid : [" << date << "]" << std::endl;
		return (false);
	}
	if (day > 31 || day < 1)
	{
		std::cerr << "Day is not valid : [" << date << "]" << std::endl;
		return (false);
	}
	if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
	{
		std::cerr << "Day is not valid, no 31 this month : [" << date << "]" << std::endl;
		return (false);
	}
	if (month == 2)
	{
		if (is_bissextile == true && day > 29)
		{
			std::cerr << "Day is not valid, no 30 or 31 in february : [" << date << "]" << std::endl;
			return (false);
		}
		else if (is_bissextile == false && day > 28)
		{
			std::cerr << "Day is not valid, no 29, 30 or 31 in february in bissextile year : [" << date << "]" << std::endl;
			return (false);
		}
	}
	return (true);
}

static bool	date_validation(std::string date)
{
	size_t	len = date.length();

	if (len != 10)
	{
		std::cerr << "Date formatting error : [" << date << "]" << std::endl;
		return (false);
	}
	for (size_t i = 0 ; i < len ; i++)
	{
		if ((i < 4 || i == 5 || i == 6 || i > 7) && !isdigit(date[i]))
		{
			std::cerr << "Date formatting error : [" << date << "]" << std::endl;
			return (false);
		}
		else if ((i == 4 || i == 7) && date[i] != '-')
		{
			std::cerr << "Date formatting error : [" << date << "]" << std::endl;
			return (false);
		}
	}
	return (is_real_date(date));
}

static bool	value_validation(std::string value)
{
	size_t	len = value.length();
	double	convalue;

	for (size_t i = 0 ; i < len ; i++)
	{
		if (!isdigit(value[i]) && value[i] != '.' && value[i] != '-')
		{
			std::cerr << "Error: Value is not a number : [" << value << "]" << std::endl;
			return (false);
		}
	}
	convalue = strtod(value.c_str(), NULL);
	if (convalue < 0)
	{
		std::cerr << "Error: not a positive number : [" << value << "]" << std::endl;
		return (false);
	}
	if (convalue > 1000.0)
	{
		std::cerr << "Error: too large a number : [" << value << "]" << std::endl;
		return (false);
	}
	return (true);
}

static void	search_and_display(std::map<std::string, float> main_db, std::string date, float value)
{
	std::string								line;
	std::map<std::string, float>::iterator	it = main_db.begin();

	it = main_db.upper_bound(date);
	if (it == main_db.begin())
	{
		std::cerr << "Error: No suitable date : [" << date << "]" << std::endl;
		return ;
	}
	--it;
	std::cout << "[" << date << "] => [" << value << "] = [" << it->second * value << "]" << std::endl;
}
