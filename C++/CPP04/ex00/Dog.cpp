/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:13:11 by btani             #+#    #+#             */
/*   Updated: 2024/01/23 16:01:33 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";

};

Dog::Dog(const Dog& copy): Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = "Dog";
};

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
};

Dog&	Dog::operator=(const Dog& op)
{
	std::cout << "Dog copy assignament operator called" << std::endl;
	
	if (this != &op)
		this->_type = op._type; 
	return *this;
};

void Dog::makeSound(void) const
{
	std::cout << "Sound of a dog...BAUBAU!" << std::endl;	
};

