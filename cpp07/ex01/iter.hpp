/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 23:23:41 by tle-pape          #+#    #+#             */
/*   Updated: 2026/02/05 23:23:41 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T *array, const size_t len, void (*func)(T &arg))
{
	if (!array || !func)
		return ;
	for (size_t i = 0 ; i < len ; i++)
		func(array[i]);
}

template <typename T>
void	iter(T *array, const size_t len, void (*func)(const T &arg))
{
	if (!array || !func)
		return ;
	for (size_t i = 0 ; i < len ; i++)
		func(array[i]);
}

#endif
