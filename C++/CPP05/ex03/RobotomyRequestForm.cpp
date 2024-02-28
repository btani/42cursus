/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:13:00 by btani             #+#    #+#             */
/*   Updated: 2024/02/21 18:20:11 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm(),  _target("def")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm param constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& copy): AForm(copy), _target(copy._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = copy;
};

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
};

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& op)
{
	if(this != &op)
		this->_target = op._target;
	return *this;
};

AForm* RobotomyRequestForm::createForm(const std::string& formTarget)
{
	return new RobotomyRequestForm(formTarget);
};

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	checkExecution(executor);
	static int i;
	if (i % 2 == 0)
		std::cout << "... dirlling noises ..." << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << this->_target << " failed!" << std::endl;
	i++;
};
