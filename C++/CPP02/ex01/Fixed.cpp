/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:32:42 by btani             #+#    #+#             */
/*   Updated: 2024/02/03 18:28:51 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ): _fixedNbr(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed( const int nbr ): _fixedNbr(nbr << _fractBits)
{
	std::cout << "Int constructor called" << std::endl;
};

//roundf(): round a floating-point number to the nearest integer, following the "round half to even" rule.
//returns a floating-point value,
Fixed::Fixed( const float nbr ) : _fixedNbr(roundf(nbr * (1 << _fractBits)))
{
	std::cout << "Float constructor called" << std::endl;
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
	std::cout << "'getRawBits' member function called" << std::endl;
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

/*converts the fixed-point value to a floating-point value
static_cast for explicit type conversion
After float convertion , the result is divided by scaleFactor, value adjusted
on the position of the decimal point in the fixed-point representation.*/
float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_fixedNbr) / (1 << _fractBits));
};

//converts the fixed-point value to an integer value
int Fixed::toInt( void ) const
{
	return ((this->_fixedNbr) / (1 << _fractBits));	
};

std::ostream& operator<<(std::ostream& o, const Fixed& rhs)
{
	o << rhs.toFloat();
	return o;
};
