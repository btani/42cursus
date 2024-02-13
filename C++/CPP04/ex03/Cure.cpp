/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:40:07 by btani             #+#    #+#             */
/*   Updated: 2024/02/13 15:50:20 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
};

Cure::Cure(const Cure& copy): AMateria("cure")
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = copy;
};

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
};

Cure& Cure::operator=(const Cure& op)
{
	std::cout << "Cure assignation operator called" << std::endl;
	if (this != &op)
		this->_materiaType = op._materiaType;
	return (*this);
};

AMateria* Cure::clone(void) const
{
	std::cout << "Cure clone called" << std::endl;
	return (new Cure(*this));
};

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	std::cout << std::endl;
};
