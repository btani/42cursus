/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:26:16 by btani             #+#    #+#             */
/*   Updated: 2024/02/21 19:45:24 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

class AForm;

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
};

Intern::Intern(const Intern& copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
};

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
};

Intern& Intern::operator=(Intern const& op)
{
	std::cout << "Intern assignation operator called" << std::endl;
	return *this;
};

//return a pointer to a Form object (whose name passed as parameter) whose target is initialized to the second parameter
AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget) const
{
	std::string requestedForm[] = {"shrubbery request", "robotomy request", "presidential request"};
	std::string typeForm[] = {"shrubbery", "robotmy", "presidential"};

	AForm* (*f[])(const std::string& formTarget) = {&ShrubberyCreationForm::createForm, &RobotomyRequestForm::createForm, &PresidentialPardonForm::createForm};
	for (size_t i = 0; i < 3; i++)
	{
		if (!requestedForm[i].compare(formName) || !typeForm[i].compare(formName))
		{
			std::cout << "Intern creates " << typeForm[i] << " form." << std::endl;
			return f[i](formTarget);
		}
	}
	std::cout << "Error: the form doesn't exist." << std::endl;
	return (NULL);		
};
