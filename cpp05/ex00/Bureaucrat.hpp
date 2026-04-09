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

# define DEFAULT_CONSTRUCTOR "Default constructor called"
# define DEFAULT_COPY_CONSTRUCTOR "Default copy constructor called"
# define DEFAULT_ASSIGNATION_CONSTRUCTOR "Default assignation constructor called"
# define DEFAULT_DESTRUCTOR "Default destructor called"
# define OVERLOAD_CONSTRUCTOR "Overload constructor called"
# define MAX_GRADE 1
# define MIN_GRADE 150

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

	int				getGrade();
	std::string		getName();
	void			incrementGrade();
	void			decrementGrade();

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
