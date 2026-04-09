/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:47:34 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/29 09:47:34 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << DEFAULT_CONSTRUCTOR << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << DEFAULT_COPY_CONTRUCTOR << std::endl;
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	std::cout << DEFAULT_ASSIGNATION_CONSTRUCTOR << std::endl;
	(void)other;
	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << DEFAULT_DESTRUCTOR << std::endl;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
