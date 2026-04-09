/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-29 11:05:08 by tle-pape          #+#    #+#             */
/*   Updated: 2026-01-29 11:05:08 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

struct	Data
{
	std::string		s1;
	std::string		s2;
	unsigned int	start;
	unsigned int	stop;
};

std::ostream	&operator<<(std::ostream &o, const Data &obj);

#endif
