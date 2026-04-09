/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:05:47 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/12 15:05:47 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) :
	name("default_AForm"), sign_requirement(150),
	exec_requirement(150), is_signed(false)
{
	std::cout << DEFAULT_AFORM_CONSTRUCTOR << std::endl;
}

AForm::AForm(const AForm &other) :
	name(other.name), sign_requirement(other.sign_requirement),
	exec_requirement(other.exec_requirement), is_signed(other.is_signed)
{
	std::cout << DEFAULT_AFORM_COPY_CONSTRUCTOR << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << DEFAULT_AFORM_ASSIGNATION_CONSTRUCTOR << std::endl;
	if (this == &other)
		return (*this);
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << DEFAULT_AFORM_DESTRUCTOR << std::endl;
}

AForm::AForm(std::string new_aform_name, int sign_grade, int exec_grade) :
	name(new_aform_name), sign_requirement(sign_grade),
	exec_requirement(exec_grade), is_signed(false)
{
	std::cout << OVERLOAD_AFORM_CONSTRUCTOR << std::endl;
	if (sign_grade > 150 || sign_grade < 1)
	{
		std::cout << "Sign grade requirement error :";
		throw AForm::GradeTooLowException();
	}
	else if (exec_grade > 150 || exec_grade < 1)
	{
		std::cout << "Exec grade requirement error :";
		throw AForm::GradeTooLowException();
	}
}

std::string	AForm::getName(void)
{
	return (name);
}

bool	AForm::getSignedState(void) const
{
	return (is_signed);
}

int	AForm::getSignRequirement(void)
{
	return (sign_requirement);
}

int	AForm::getExecRequirement(void)
{
	return (exec_requirement);
}

bool	AForm::beSigned(Bureaucrat *bureaucrat)
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
		std::cout << name << " has been signed !" << std::endl;
		to_return = true;
	}
	return (to_return);
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->exec_requirement)
		throw GradeTooLowException();
	else if (this->getSignedState() == false)
		throw NotSignedFormException();
	else
	{
		this->execute_form();
		std::cout << name << " has been executed !" << std::endl;
	}
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high !");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low !");
}

const char *AForm::NotSignedFormException::what(void) const throw()
{
	return ("Form is not signed !");
}

std::ostream	&operator<<(std::ostream &o, AForm &obj)
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

std::ostream	&operator<<(std::ostream &o, AForm *obj)
{
	if (!obj)
	{
		o << "Object not found.";
		return (o);
	}
	o << "[" << obj->getName() << "], need grade [" << obj->getSignRequirement()
		<< "] to be signed, grade [" << obj->getExecRequirement()
		<< "] to be executed. Current state : ";
	if (obj->getSignedState() == 0)
		o << "false.";
	else
		o << "true.";
	return (o);
}
