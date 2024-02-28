/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:12:45 by btani             #+#    #+#             */
/*   Updated: 2024/02/21 18:20:31 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm(),  _target("def")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm param constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& copy): AForm(copy), _target(copy._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = copy;
};

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& op)
{
	if(this != &op)
		this->_target = op._target;
	return *this;
};

AForm* PresidentialPardonForm::createForm(const std::string& formTarget)
{
	return new PresidentialPardonForm(formTarget);
};

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	checkExecution(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
};
