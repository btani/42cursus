/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:13:16 by btani             #+#    #+#             */
/*   Updated: 2024/02/23 14:51:54 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

class AForm;

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm(), _target("def")	
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm param constructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& copy) : AForm(copy), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = copy;
};

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& op)
{
	if (this != &op)
		this->_target = op._target;
	return *this;
};

/*execute the form’s action of the concrete classes:
check that the form is signed and that the grade of the bureaucrat
attempting to execute the form is high enough. Otherwise, throw an 
appropriate exception.*/
void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    (void)executor;
	std::string	target = this->_target + "_shrubbery";
	std::ofstream file(target.c_str());
	if (!file.is_open())
	{
		std::cout << "Error can't open the file" << std::endl;
		return ;
	}
	else
	{
		file << "		                  %%%,%%%%%%% " << std::endl;
		file << "                   ,'%% \\-*%%%%%%% " << std::endl;
		file << "             ;%%%%%*%   _%%%%' " << std::endl;
		file << "              ,%%%       \\(_.*%%%%. " << std::endl;
		file << "              % *%%, ,%%%%*(    ' " << std::endl;
		file << "            %^     ,*%%% )\\|,%%*%,_ " << std::endl;
		file << "                 *%   \\/ #).-'*%%* " << std::endl;
		file << "                     _.) ,/ *%, " << std::endl;
		file << "             _________) #(_____________ " << std::endl;
		file.close();
	} 
};
