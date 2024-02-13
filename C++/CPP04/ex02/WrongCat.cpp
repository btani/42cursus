/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:11:54 by btani             #+#    #+#             */
/*   Updated: 2024/01/24 18:05:12 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): _type("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
};

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->_type = "WrongCat";
};

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
};

WrongCat&	WrongCat::operator=(const WrongCat& op)
{
	std::cout << "WrongCat copy assignament operator called" << std::endl;
	
	if (this != &op)
		this->_type = op._type; 
	return *this;
};

void WrongCat::makeSound(void) const
{
	std::cout << "Sound of a WrongCat...PIOPIO!" << std::endl;
	std::cout << std::endl;
};
