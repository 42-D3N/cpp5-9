/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:44:37 by tle-pape          #+#    #+#             */
/*   Updated: 2026/02/13 15:44:39 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

std::ostream	&operator<<(std::ostream &o, const Data &obj)
{
	o	<< "String 1       : [" << obj.s1 << "]" << std::endl
		<< "String 2       : [" << obj.s2 << "]" << std::endl
		<< "Unsigned int 1 : [" << obj.start << "]" << std::endl
		<< "Unsigned int 2 : [" << obj.stop << "]" << std::endl;
	return (o);
}
