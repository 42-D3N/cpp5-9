/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:47:10 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/14 10:47:10 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <time.h>
# include <stdlib.h>
# include "AForm.hpp"

# define DEFAULT_ROBOTFORM_CONSTRUCTOR "Default RobotomyRequestForm constructor called"
# define DEFAULT_ROBOTFORM_COPY_CONSTRUCTOR "Default RobotomyRequestForm copy constructor called"
# define DEFAULT_ROBOTFORM_ASSIGNATION_CONSTRUCTOR "Default RobotomyRequestForm assignation constructor called"
# define DEFAULT_ROBOTFORM_DESTRUCTOR "Default RobotomyRequestForm destructor called"
# define OVERLOAD_ROBOTFORM_CONSTRUCTOR "Overload RobotomyRequestForm constructor called"
# define ROBOT_SIGN 72
# define ROBOT_EXEC 45

class RobotomyRequestForm : public AForm
{
private:
	std::string		target;
	void	execute_form(void) const;

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm(void);
	RobotomyRequestForm(std::string new_target);
};

#endif
