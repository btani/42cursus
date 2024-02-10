/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:06:49 by btani             #+#    #+#             */
/*   Updated: 2024/02/04 18:25:41 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//CONSTRUCTOR
Fixed::Fixed( void ): _fixedNbr(0) { };

Fixed::Fixed( const int nbr ): _fixedNbr(nbr << _fractBits) { };

Fixed::Fixed( const float nbr ) : _fixedNbr(roundf(nbr * (1 << _fractBits))) { };

Fixed::Fixed( const Fixed& src ) { *this = src; };

//DESTRUCTOR
Fixed::~Fixed( void ) { };

Fixed& Fixed::operator=( const Fixed& rhs )
{
	if (this != &rhs)
		this->_fixedNbr = rhs.getRawBits();
	return *this;
};

//COMPARISON OPERATORS
bool Fixed::operator>( const Fixed& rhs) const
{
	if (this->getRawBits() > rhs.getRawBits())
		return true;
	return false;
};

bool Fixed::operator<( const Fixed& rhs) const
{
	if (this->getRawBits() < rhs.getRawBits())
		return true;
	return false;
};

bool Fixed::operator>=( const Fixed& rhs) const
{
	if (this->getRawBits() >= rhs.getRawBits())
		return true;
	return false;
};

bool Fixed::operator<=( const Fixed& rhs) const
{
	if (this->getRawBits() <= rhs.getRawBits())
		return true;
	return false;
};

bool Fixed::operator==( const Fixed& rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return true;
	return false;
};

bool Fixed::operator!=( const Fixed& rhs) const
{
	if (this->getRawBits() != rhs.getRawBits())
		return true;
	return false;
};

//ARITHMETIC OPERATORS
Fixed	Fixed::operator+( const Fixed& rhs ) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
};

Fixed	Fixed::operator-( const Fixed& rhs ) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
};

Fixed	Fixed::operator*( const Fixed& rhs ) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
};

Fixed	Fixed::operator/( const Fixed& rhs ) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
};

//INCREMENT-DECREMENT OPERATORS
Fixed&	Fixed::operator++( void )
{
	++this->_fixedNbr;
	return *this;	
};

Fixed	Fixed::operator++( int )
{
	Fixed	tmp = *this;
	this->_fixedNbr++;
	return (tmp);
};

Fixed&	Fixed::operator--( void )
{
	--this->_fixedNbr;
	return *this;	
};

Fixed	Fixed::operator--( int )
{
	Fixed	tmp = *this;
	this->_fixedNbr--;
	return (tmp);
};

//MEMBER FUNCTIONS
int Fixed::getRawBits( void ) const
{
	return this->_fixedNbr;
};

void Fixed::setRawBits( int const raw )
{
	this->_fixedNbr = raw;
};

//converts the fixed-point value to a float value
float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_fixedNbr) / (1 << _fractBits));
};

//converts the fixed-point value to an integer value
int Fixed::toInt( void ) const
{
	return ((this->_fixedNbr) / (1 << _fractBits));	
};

//STATIC MEMBER FUNCTIONS OVERLOAD
Fixed& Fixed::min( Fixed& nbrA, Fixed& nbrB )
{
	if (nbrA.getRawBits() < nbrB.getRawBits())
		return nbrA;
	return nbrB;	
};

Fixed& Fixed::max( Fixed& nbrA, Fixed& nbrB )
{
	if (nbrA.getRawBits() > nbrB.getRawBits())
		return nbrA;
	return nbrB;
};

const Fixed& Fixed::min( const Fixed& nbrA, const Fixed& nbrB )
{
	if (nbrA.getRawBits() < nbrB.getRawBits())
		return nbrA;
	return nbrB;
};

const Fixed& Fixed::max( const Fixed& nbrA, const Fixed& nbrB )
{
	if (nbrA.getRawBits() > nbrB.getRawBits())
		return nbrA;
	return nbrB;
};

std::ostream& operator<<( std::ostream& o, const Fixed& rhs )
{
	o << rhs.toFloat();
	return o;
};
