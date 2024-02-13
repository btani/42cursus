/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:40:15 by btani             #+#    #+#             */
/*   Updated: 2024/02/13 15:50:29 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
};

Ice::Ice(const Ice& copy): AMateria(copy)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = copy;
};

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
};

Ice& Ice::operator=(const Ice& op)
{
	std::cout << "Ice assignation operator called" << std::endl;
	if (this != &op)
		this->_materiaType = op._materiaType;
	return (*this);
};

AMateria* Ice::clone(void) const
{
	std::cout << "Ice clone called" << std::endl;
	return (new Ice(*this));
};

void Ice::use(ICharacter& target)
{
	std::cout << std::endl;
	std::cout << "* shoot an ice bolt at " << target.getName() << " *" << std::endl;
};

