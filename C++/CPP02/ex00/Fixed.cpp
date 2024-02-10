/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:43:06 by btani             #+#    #+#             */
/*   Updated: 2023/12/15 18:30:46 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ): _fixedNbr(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed( const Fixed& src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
};

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedNbr;
};

void Fixed::setRawBits( int const raw )
{
	this->_fixedNbr = raw;
};

Fixed& Fixed::operator=( const Fixed& rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedNbr = rhs.getRawBits();
	return *this;
};
