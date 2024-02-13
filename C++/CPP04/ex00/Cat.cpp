/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:13:25 by btani             #+#    #+#             */
/*   Updated: 2024/01/15 18:17:22 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
};

Cat::Cat(const Cat& copy): Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = "Cat";
};

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
};

Cat&	Cat::operator=(const Cat& op)
{
	std::cout << "Cat copy assignament operator called" << std::endl;
	
	if (this != &op)
		this->_type = op._type; 
	//(void)op;
	return *this;
};

void Cat::makeSound(void) const
{
	std::cout << "Sound of a cat...MIAOMIAO!" << std::endl;	
};
