/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:47:34 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/29 09:47:34 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

# define DEFAULT_CONSTRUCTOR "Default constructor (Serializer) called !"
# define DEFAULT_COPY_CONTRUCTOR "Default copy constructor (Serializer) called !"
# define DEFAULT_ASSIGNATION_CONSTRUCTOR "Default assignation constructor (Serializer) called !"
# define DEFAULT_DESTRUCTOR "Default destructor (Serializer) called !"

class Serializer
{
private:
	Serializer(void);
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer(void);

public:
	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);
};

#endif
