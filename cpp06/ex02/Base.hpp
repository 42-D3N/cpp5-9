/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:03:55 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/29 13:03:55 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <time.h>
# include <cstdlib>

# define DEFAULT_DESTRUCTOR "Default destructor (Base) called !"

class Base
{
public:
	virtual ~Base(void);
};

#endif
