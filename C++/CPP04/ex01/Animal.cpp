/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:14:13 by btani             #+#    #+#             */
/*   Updated: 2024/01/23 15:06:48 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type(" ")
{
	std::cout << "Animal default constructor called" << std::endl;
};

Animal::Animal(const Animal& copy): _type(" ")
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
};

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
};

Animal&	Animal::operator=(const Animal& op)
{
	std::cout << "Animal copy assignament operator called" << std::endl;
	
	if (this != &op)
		this->_type = op._type; 
	return *this;
};

std::string	Animal::getType(void) const
{
	return this->_type;
};

void Animal::makeSound(void) const
{
	std::cout << "Sound of an animal...which one?!" << std::endl;	
};
