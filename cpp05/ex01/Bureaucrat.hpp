/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:34:56 by tle-pape          #+#    #+#             */
/*   Updated: 2025/12/09 10:34:56 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

# define DEFAULT_BUREAUCRAT_CONSTRUCTOR "Default Bureaucrat constructor called"
# define DEFAULT_BUREAUCRAT_COPY_CONSTRUCTOR "Default Bureaucrat copy constructor called"
# define DEFAULT_BUREAUCRAT_ASSIGNATION_CONSTRUCTOR "Default Bureaucrat assignation constructor called"
# define DEFAULT_BUREAUCRAT_DESTRUCTOR "Default Bureaucrat destructor called"
# define OVERLOAD_BUREAUCRAT_CONSTRUCTOR "Overload Bureaucrat constructor called"
# define MAX_GRADE 1
# define MIN_GRADE 150

class Form;

class	Bureaucrat
{
private:
	const std::string	name;
	unsigned char		grade;

public:
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat(void);
	Bureaucrat(std::string new_name, int new_grade);

	int				getGrade(void);
	std::string		getName(void);
	void			incrementGrade(void);
	void			decrementGrade(void);
	void			signForm(Form *form_to_sign);

	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat &obj);

#endif
