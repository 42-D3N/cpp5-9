/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:34:56 by tle-pape          #+#    #+#             */
/*   Updated: 2025/12/09 10:34:56 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) :
	name("it"), grade(150)
{
	std::cout << DEFAULT_BUREAUCRAT_CONSTRUCTOR << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	name(other.name)
{
	std::cout << DEFAULT_BUREAUCRAT_COPY_CONSTRUCTOR << std::endl;
	this->grade = other.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << DEFAULT_BUREAUCRAT_ASSIGNATION_CONSTRUCTOR << std::endl;
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << DEFAULT_BUREAUCRAT_DESTRUCTOR << std::endl;
}

Bureaucrat::Bureaucrat(std::string new_name, int new_grade): name(new_name)
{
	std::cout << OVERLOAD_BUREAUCRAT_CONSTRUCTOR << std::endl;
	if (new_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (new_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade = new_grade;
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high !");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low !");
}

void	Bureaucrat::decrementGrade(void)
{
	if (grade == MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

void	Bureaucrat::incrementGrade(void)
{
	if (grade == MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

std::string	Bureaucrat::getName(void)
{
	return (name);
}

int	Bureaucrat::getGrade(void) const
{
	return (grade);
}

void	Bureaucrat::signForm(AForm *form_to_sign)
{
	bool	is_signed = form_to_sign->getSignedState();

	if (is_signed == false)
	{
		form_to_sign->beSigned(this);
		if (form_to_sign->getSignedState() == is_signed)
		{
			std::cout << name << " couldn't sign " << form_to_sign->getName()
				<< " because : ";
			throw GradeTooLowException();
		}
		else
			std::cout << name << " signed " << form_to_sign->getName() << std::endl;
	}
	else
	{
		form_to_sign->beSigned(this);
		if (form_to_sign->getSignedState() == is_signed)
		{
			std::cout << name << " couldn't unsign " << form_to_sign->getName()
				<< " because : ";
			throw GradeTooLowException();
		}
		else
			std::cout << name << " unsigned " << form_to_sign->getName() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	form.execute(*this);
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat &a)
{
	o << "[" << a.getName() << "], bureaucrat grade [" << a.getGrade() << "]";
	return (o);
}
