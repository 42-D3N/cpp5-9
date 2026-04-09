/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:47:18 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/14 10:47:18 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

# define DEFAULT_PRESIFORM_CONSTRUCTOR "Default PresidentialPardonForm constructor called"
# define DEFAULT_PRESIFORM_COPY_CONSTRUCTOR "Default PresidentialPardonForm copy constructor called"
# define DEFAULT_PRESIFORM_ASSIGNATION_CONSTRUCTOR "Default PresidentialPardonForm assignation constructor called"
# define DEFAULT_PRESIFORM_DESTRUCTOR "Default PresidentialPardonForm destructor called"
# define OVERLOAD_PRESIFORM_CONSTRUCTOR "Overload PresidentialPardonForm constructor called"
# define PRESI_SIGN 25
# define PRESI_EXEC 5

class PresidentialPardonForm : public AForm
{
private:
	std::string	target;
	void		execute_form(void) const;

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
};

#endif
