/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:35:12 by tle-pape          #+#    #+#             */
/*   Updated: 2025/12/09 10:35:13 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data	dat;
	Data	*dat_cpy;
	dat.s1 = "Heyo";
	dat.s2 = "Come join the fun.";
	dat.start = 0;
	dat.stop = 22;

	std::cout << "\e[4mBefore Serialization  :\e[0m" << std::endl << dat;

	uintptr_t	raw = Serializer::serialize(&dat);
	std::cout << std::endl << "\e[4mSerialized :\e[0m" << std::endl
		<< "uintptr_t raw  : [" << raw << "]" << std::endl << std::endl;

	dat_cpy = Serializer::deserialize(raw);
	std::cout << "\e[4mAfter deserialization :\e[0m" << std::endl << dat;
}
