/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:05:47 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/12 15:05:47 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) :
	name("default_form"), sign_requirement(150),
	exec_requirement(150), is_signed(false)
{
	std::cout << DEFAULT_FORM_CONSTRUCTOR << std::endl;
}

Form::Form(const Form &other) :
	name(other.name), sign_requirement(other.sign_requirement),
	exec_requirement(other.exec_requirement), is_signed(other.is_signed)
{
	std::cout << DEFAULT_FORM_COPY_CONSTRUCTOR << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << DEFAULT_FORM_ASSIGNATION_CONSTRUCTOR << std::endl;
	if (this != &other)
	{
		is_signed = other.is_signed;
	}
	return (*this);
}

Form::~Form(void)
{
	std::cout << DEFAULT_FORM_DESTRUCTOR << std::endl;
}

Form::Form(std::string new_form_name, int sign_grade, int exec_grade) :
	name(new_form_name), sign_requirement(sign_grade),
	exec_requirement(exec_grade), is_signed(false)
{
	std::cout << OVERLOAD_FORM_CONSTRUCTOR << std::endl;
	if (sign_grade > 150 || sign_grade < 1)
	{
		std::cout << "Sign grade requirement error :";
		if (sign_grade > 150)
			throw Form::GradeTooLowException();
		else
			throw Form::GradeTooHighException();
	}
	else if (exec_grade > 150 || exec_grade < 1)
	{
		std::cout << "Exec grade requirement error :";
		if (exec_grade > 150)
			throw Form::GradeTooLowException();
		else
			throw Form::GradeTooHighException();
	}
}

std::string	Form::getName(void)
{
	return (name);
}

int	Form::getSignRequirement(void)
{
	return (sign_requirement);
}

int	Form::getExecRequirement(void)
{
	return (exec_requirement);
}

bool	Form::getSignedState(void)
{
	return (is_signed);
}

bool	Form::beSigned(Bureaucrat *bureaucrat)
{
	bool	to_return;

	if (bureaucrat->getGrade() > sign_requirement)
	{
		throw GradeTooLowException();
		to_return = false;
	}
	else
	{
		is_signed = !is_signed;
		to_return = true;
	}
	return (to_return);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high !");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low !");
}

std::ostream	&operator<<(std::ostream &o, Form &obj)
{
	o << "[" << obj.getName() << "], need grade [" << obj.getSignRequirement()
		<< "] to be signed, grade [" << obj.getExecRequirement()
		<< "] to be executed. Current state : ";
	if (obj.getSignedState() == 0)
		o << "false.";
	else
		o << "true.";
	return (o);
}
