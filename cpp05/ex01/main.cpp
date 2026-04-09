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
#include "Form.hpp"

int	main()
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
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Bureaucrat	too_low("toohigh", 0);
		}
		catch(const std::exception& e)
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
		std::cout << std::endl;
		std::cout << std::endl;

		Bureaucrat	highest("high_grade", 1);
		Bureaucrat	lowest("low_grade", 150);
		Form		formtest("Formulaire A38", 75, 75);
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << formtest << std::endl;
		highest.signForm(&formtest);
		highest.signForm(&formtest);
		try
		{
			lowest.signForm(&formtest);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		highest.signForm(&formtest);
		std::cout << std::endl;
		std::cout << std::endl;

		Form		form_copy(formtest);
		Form		form_assign;

		form_assign = formtest;
		std::cout << std::endl;
		std::cout << form_copy << std::endl << form_assign << std::endl;
		std::cout << std::endl;
	}
}
