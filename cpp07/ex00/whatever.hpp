/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:10:51 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/30 16:10:51 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
T	&min(T &a, T &b)
{
	return (a < b ? a : b);
}

template <typename T>
T	&max(T &a, T &b)
{
	return (a > b ? a : b);
}

#endif
