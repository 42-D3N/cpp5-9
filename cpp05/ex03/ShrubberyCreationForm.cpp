/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:46:52 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/14 10:46:52 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("ShrubberyCreation", SHRUB_SIGN, SHRUB_EXEC), path("none")
{
	std::cout << DEFAULT_SHRUBFORM_CONSTRUCTOR << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm("ShrubberyCreation", SHRUB_SIGN, SHRUB_EXEC)
{
	std::cout << DEFAULT_SHRUBFORM_COPY_CONSTRUCTOR << std::endl;
	path = other.path;
	path.append("_cpy");
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << DEFAULT_SHRUBFORM_ASSIGNATION_CONSTRUCTOR << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << DEFAULT_SHRUBFORM_DESTRUCTOR << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string new_path) :
	AForm("ShrubberyCreation", SHRUB_SIGN, SHRUB_EXEC), path(new_path)
{
	std::cout << OVERLOAD_SHRUBFORM_CONSTRUCTOR << std::endl;
}

void	ShrubberyCreationForm::execute_form(void) const
{
	std::ofstream	outfile;
	std::string		true_path;

	true_path = path;
	true_path.append("_shrubbery");
	outfile.open(true_path.c_str());
	outfile << TREE_1 << std::endl << std::endl << TREE_2;
	outfile.close();
}
