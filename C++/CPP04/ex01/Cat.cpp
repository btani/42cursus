/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:13:25 by btani             #+#    #+#             */
/*   Updated: 2024/02/13 15:26:17 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
//deep copy: it makes a full copy of an object, including the objects pointed to by the original one


Cat::Cat(void): Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain;
};

Cat::Cat(const Cat& copy): Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = "Cat";
};

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
};

Cat&	Cat::operator=(const Cat& op)
{
	std::cout << "Cat copy assignament operator called" << std::endl;
	
	if (this != &op)
		this->_type = op._type; 
	return *this;
};

void Cat::makeSound(void) const
{
	std::cout << "Sound of a cat...MIAOMIAO!" << std::endl;	
};
