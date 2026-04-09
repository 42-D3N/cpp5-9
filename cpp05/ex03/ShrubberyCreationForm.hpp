/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:46:52 by tle-pape          #+#    #+#             */
/*   Updated: 2026/01/14 10:46:52 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

# define DEFAULT_SHRUBFORM_CONSTRUCTOR "Default ShrubberyFormCreation constructor called"
# define DEFAULT_SHRUBFORM_COPY_CONSTRUCTOR "Default ShrubberyFormCreation copy constructor called"
# define DEFAULT_SHRUBFORM_ASSIGNATION_CONSTRUCTOR "Default ShrubberyFormCreation assignation constructor called"
# define DEFAULT_SHRUBFORM_DESTRUCTOR "Default ShrubberyFormCreation destructor called"
# define OVERLOAD_SHRUBFORM_CONSTRUCTOR "Overload ShrubberyFormCreation constructor called"
# define SHRUB_SIGN 145
# define SHRUB_EXEC 137

# define TREE_1 "\
     v .   ._, |_  .,\n\
  `-._\\/  .  \\ /    |/_ \n\
      \\  _\\, y | \\// \n\
_\\_.___\\, \\/ -.\\|| \n\
  `7-,--.`._||  / / , \n\
  /'     `-. `./ / |/_.' \n\
            |    |// \n\
            |_    / \n\
            |-   | \n\
            |   =| \n\
            |    |"

# define TREE_2 "\
       _-_\n\
    /~~   ~~\\\n\
 /~~         ~~\\\n\
{               }\n\
 \\  _-     -_  /\n\
   ~  \\\\ //  ~\n\
_- -   | | _- _\n\
  _ -  | |   -_\n\
      // \\\\"

class ShrubberyCreationForm : public AForm
{
private:
	std::string path;

	void	execute_form(void) const;

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string new_path);
};

#endif
