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

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "D.hpp"

void	identify(Base& p);
void	identify(Base* p);
Base	*generate(void);

int	main(void)
{
	{
		Base	*base;

		base = generate();
		identify(base);
		identify(*base);

		delete(base);
	}
	{
		Base *d = new D;

		identify(d);
		identify(*d);

		delete(d);
	}
}
