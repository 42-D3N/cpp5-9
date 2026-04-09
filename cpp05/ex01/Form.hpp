/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:05:47 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/12 15:05:47 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

# define DEFAULT_FORM_CONSTRUCTOR "Default Form constructor called"
# define DEFAULT_FORM_COPY_CONSTRUCTOR "Default Form copy constructor called"
# define DEFAULT_FORM_ASSIGNATION_CONSTRUCTOR "Default Form assignation constructor called"
# define DEFAULT_FORM_DESTRUCTOR "Default Form destructor called"
# define OVERLOAD_FORM_CONSTRUCTOR "Overload Form constructor called"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	const int			sign_requirement;
	const int			exec_requirement;
	bool				is_signed;

public:
	Form(void);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form(void);
	Form(std::string new_form_name, int sign_grade, int exec_grade);

	std::string	getName(void);
	bool		getSignedState(void);
	int			getSignRequirement(void);
	int			getExecRequirement(void);
	bool		beSigned(Bureaucrat *bureaucrat);

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
};

std::ostream	&operator<<(std::ostream &o, Form &obj);

#endif
