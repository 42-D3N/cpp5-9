/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:41:03 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/14 18:41:03 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern(void);

	AForm	*makeForm(std::string form_name, std::string form_target);
};

#endif
