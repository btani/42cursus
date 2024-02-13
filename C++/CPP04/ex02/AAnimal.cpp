/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:14:13 by btani             #+#    #+#             */
/*   Updated: 2024/01/24 18:15:29 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*An abstract class is a class that cannot be instantiated directly;
it serves as a template for other derived classes. The abstract class 
can contain pure virtual methods and/or default implementations for methods.
We can declare an abstract class by including at least one pure virtual method
A pure virtual method is a method that must be implemented
by derived classes but has no implementation in the base class.*/
#include "AAnimal.hpp"

AAnimal::AAnimal(void): _type(" ")
{
	std::cout << "AAnimal default constructor called" << std::endl;
};

AAnimal::AAnimal(const AAnimal& copy): _type(" ")
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = copy;
};

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
};

AAnimal& AAnimal::operator=(const AAnimal& op)
{
	std::cout << "AAnimal copy assignament operator called" << std::endl;
	if (this != &op)
		this->_type = op._type; 
	return *this;
};

std::string	AAnimal::getType(void) const
{
	return this->_type;
};

void AAnimal::makeSound(void) const {}; //pure virtul method
