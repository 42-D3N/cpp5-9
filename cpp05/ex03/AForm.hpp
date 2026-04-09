/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:05:47 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/12 15:05:47 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

# define DEFAULT_AFORM_CONSTRUCTOR "Default AForm constructor called"
# define DEFAULT_AFORM_COPY_CONSTRUCTOR "Default AForm copy constructor called"
# define DEFAULT_AFORM_ASSIGNATION_CONSTRUCTOR "Default AForm assignation constructor called"
# define DEFAULT_AFORM_DESTRUCTOR "Default AForm destructor called"
# define OVERLOAD_AFORM_CONSTRUCTOR "Overload AForm constructor called"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	const int			sign_requirement;
	const int			exec_requirement;
	bool				is_signed;

protected:
	AForm(void);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	AForm(std::string new_aform_name, int sign_grade, int exec_grade);

public:
	virtual ~AForm(void);
	std::string		getName(void);
	int				getSignRequirement(void);
	int				getExecRequirement(void);
	bool			getSignedState(void) const;
	bool			beSigned(Bureaucrat *bureaucrat);
	void			execute(Bureaucrat const &executor) const;
	virtual void	execute_form(void) const = 0;

	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class	NotSignedFormException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, AForm &obj);
std::ostream	&operator<<(std::ostream &o, AForm *obj);

#endif
