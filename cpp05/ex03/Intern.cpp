/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:41:03 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/14 18:41:03 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern(void)
{}

static AForm	*makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(std::string form_name, std::string form_target)
{
	const std::string	tab[3] =
	{
		"presidential pardon",
		"shrubbery creation",
		"robotomy request"
	};
	AForm	*(*funcs[])(const std::string target) =
	{
		&makePresidentialPardonForm,
		&makeShrubberyCreationForm,
		&makeRobotomyRequestForm
	};

	for (int i = 0 ; i < 3; i++)
	{
		if (form_name == tab[i])
		{
			std::cout << "Found : " << tab[i] << std::endl;
			return (funcs[i](form_target));
		}
	}
	std::cout << "Form name not found (" << form_name << ")." << std::endl;
	return (NULL);
}
