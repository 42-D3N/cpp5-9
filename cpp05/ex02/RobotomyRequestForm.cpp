/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:47:10 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/14 10:47:10 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("RobotomyRequest", ROBOT_SIGN, ROBOT_EXEC), target("none")
{
	std::cout << DEFAULT_ROBOTFORM_CONSTRUCTOR << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm("RobotomyRequest", ROBOT_SIGN, ROBOT_EXEC)
{
	std::cout << DEFAULT_ROBOTFORM_COPY_CONSTRUCTOR << std::endl;
	target = other.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << DEFAULT_ROBOTFORM_ASSIGNATION_CONSTRUCTOR << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << DEFAULT_ROBOTFORM_DESTRUCTOR << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string new_target) :
	AForm("RobotomyRequest", ROBOT_SIGN, ROBOT_EXEC), target(new_target)
{
	std::cout << OVERLOAD_ROBOTFORM_CONSTRUCTOR << std::endl;
}

void	RobotomyRequestForm::execute_form(void) const
{
	int	random;

	srand(time(0));
	random = rand() % 2;
	if (random == 0)
		std::cout << target << " has been robotomized successfully !" << std::endl;
	else
		std::cout << target << " robotomization failed !" << std::endl;
}
