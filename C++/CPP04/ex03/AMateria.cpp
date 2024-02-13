/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:13:27 by btani             #+#    #+#             */
/*   Updated: 2024/02/13 14:22:15 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void): _materiaType("default")
{
	std::cout << "AMateria default constructor called" << std::endl;
};

AMateria::AMateria(std::string const& type): _materiaType(type)
{
	std::cout << "AMateria param constructor called" << std::endl;
};

AMateria::AMateria(const AMateria& copy)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = copy;
};

AMateria:: ~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
};
	
AMateria& AMateria::operator=(const AMateria& op)
{
	std::cout << "AMateria assignament operator called" << std::endl;
	if (this != &op)
		this->_materiaType = op._materiaType; 
	return *this;
};

//Returns the materia type	
std::string const& AMateria::getType() const
{
	return this->_materiaType;
};

void AMateria::use(ICharacter& target)
{
	std::cout << "Materia in use: " << this->_materiaType << " on " << target.getName() << std::endl;
};
 