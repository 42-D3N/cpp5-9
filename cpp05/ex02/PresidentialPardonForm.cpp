/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:47:18 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/14 10:47:18 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("PresidentialPardon", PRESI_SIGN, PRESI_EXEC), target("none")
{
	std::cout << DEFAULT_PRESIFORM_CONSTRUCTOR << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm("PresidentialPardon", PRESI_SIGN, PRESI_EXEC)
{
	target = other.target;
	std::cout << DEFAULT_PRESIFORM_COPY_CONSTRUCTOR << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << DEFAULT_PRESIFORM_ASSIGNATION_CONSTRUCTOR << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << DEFAULT_PRESIFORM_DESTRUCTOR << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string new_target) :
	AForm("PresidentialPardon", PRESI_SIGN, PRESI_EXEC), target(new_target)
{
	std::cout << OVERLOAD_PRESIFORM_CONSTRUCTOR << std::endl;
}

void	PresidentialPardonForm::execute_form(void) const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
