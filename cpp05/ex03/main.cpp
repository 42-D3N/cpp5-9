/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:35:12 by tle-pape          #+#    #+#             */
/*   Updated: 2025/12/09 10:35:13 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	{
		Bureaucrat	default_constructor;
		Bureaucrat	highest("pro", 150);
		Bureaucrat	lowest("noob", 150);

		std::cout << std::endl
			<< "Trying to create bureaucrat with too low and too high grade"
			<< std::endl;
		try
		{
			Bureaucrat	too_high("toolow", 200);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Bureaucrat	too_low("toohigh", 0);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl << "Default : " << default_constructor << std::endl
			<< "Highest (before upgrade) : " << highest << std::endl
			<< "Lowest : " << lowest << std::endl << std::endl;

		try
		{
			highest.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		highest.incrementGrade();
		std::cout << "Highest (incremented) : " << highest << std::endl;
		highest.incrementGrade();
		std::cout << "Highest (incremented) : " << highest << std::endl;
		highest.decrementGrade();
		std::cout << "Highest (decremented) : " << highest << std::endl;
		for (int i = 0 ; i < 148 ; i++)
			highest.incrementGrade();
		std::cout << "Highest (incremented 148 times) : " << highest << std::endl;

		try
		{
			highest.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Highest (incremented) : " << highest << std::endl;

		Bureaucrat	highest_copy(highest);
		Bureaucrat	highest_assign;

		highest_assign = highest;
		std::cout << std::endl;
		std::cout << "Highest copy : " << highest_copy << std::endl
			<< "Highest assign : " << highest_assign << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << std::endl;

		Bureaucrat	highest("pro", 1);
		Bureaucrat	lowest("noob", 150);
		{
			std::cout << std::endl << std::endl;
			ShrubberyCreationForm shrubbery("somewhere");
			
			std::cout << shrubbery << std::endl;
			try
			{
				highest.executeForm(shrubbery);
			}
			catch(const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			try
			{
				lowest.executeForm(shrubbery);
			}
			catch(const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			shrubbery.beSigned(&highest);
			try
			{
				shrubbery.beSigned(&lowest);
			}
			catch(const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			highest.executeForm(shrubbery);
			try
			{
				lowest.executeForm(shrubbery);
			}
			catch(const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl << std::endl;

			ShrubberyCreationForm shrub_copy(shrubbery);
			ShrubberyCreationForm shrub_assign;

			shrub_assign = shrubbery;
			std::cout << std::endl << std::endl;
			std::cout << shrub_copy << std::endl;
			std::cout << shrub_assign << std::endl;
			std::cout << std::endl << std::endl;
		}
		{
			std::cout << std::endl << std::endl;
			RobotomyRequestForm robotomy("somebody");
			
			std::cout << robotomy << std::endl;
			try
			{
				highest.executeForm(robotomy);
			}
			catch(const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			try
			{
				lowest.executeForm(robotomy);
			}
			catch(const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			robotomy.beSigned(&highest);
			try
			{
				robotomy.beSigned(&lowest);
			}
			catch(const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			highest.executeForm(robotomy);
			try
			{
				lowest.executeForm(robotomy);
			}
			catch(const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl << std::endl;

			RobotomyRequestForm robot_copy(robotomy);
			RobotomyRequestForm robot_assign;

			robot_assign = robotomy;
			std::cout << std::endl << std::endl;
			std::cout << robot_copy << std::endl;
			std::cout << robot_assign << std::endl;
			std::cout << std::endl << std::endl;
		}
		{
			std::cout << std::endl << std::endl;
			PresidentialPardonForm presidential("someone");
			
			std::cout << presidential << std::endl;
			try
			{
				highest.executeForm(presidential);
			}
			catch(const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			try
			{
				lowest.executeForm(presidential);
			}
			catch(const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			presidential.beSigned(&highest);
			try
			{
				presidential.beSigned(&lowest);
			}
			catch(const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			highest.executeForm(presidential);
			try
			{
				lowest.executeForm(presidential);
			}
			catch(const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl << std::endl;

			PresidentialPardonForm presi_copy(presidential);
			PresidentialPardonForm presi_assign;

			presi_assign = presidential;
			std::cout << std::endl << std::endl;
			std::cout << presi_copy << std::endl;
			std::cout << presi_assign << std::endl;
			std::cout << std::endl << std::endl;
		}
	}
	{
		Intern	test;

		AForm	*testform_1 = test.makeForm("invalid_form_name", "Invalid");
		AForm	*testform_2 = test.makeForm("presidential pardon", "Presi");
		AForm	*testform_3 = test.makeForm("robotomy request", "Bender");

		std::cout << std::endl;
		std::cout << "testform_1 : " << testform_1 << std::endl << std::endl;
		std::cout << "testform_2 : " << testform_2 << std::endl << std::endl;
		std::cout << "testform_3 : " << testform_3 << std::endl << std::endl;

		delete testform_1;
		delete testform_2;
		delete testform_3;
	}
}
