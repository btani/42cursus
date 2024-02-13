/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:11:42 by btani             #+#    #+#             */
/*   Updated: 2024/02/13 18:12:16 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("base")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal& copy): _type("base")
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
};

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
};

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& op)
{
	std::cout << "WrongAnimal copy assignament operator called" << std::endl;
	
	if (this != &op)
		this->_type = op._type; 
	return *this;
};

std::string	WrongAnimal::getType(void) const
{
	return this->_type;
};

void WrongAnimal::makeSound(void) const
{
	std::cout << "Sound of an animal...which one?!" << std::endl;	
};
