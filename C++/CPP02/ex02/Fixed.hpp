/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:59:33 by btani             #+#    #+#             */
/*   Updated: 2023/12/20 15:43:04 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
	
	int _fixedNbr;
	static const int _fractBits = 8;

	public:
	
	//constructor
	Fixed( void ); //canonical form constructor
	Fixed( const int nbr);
	Fixed( const float nbr);
	Fixed( const Fixed& src ); //canonical form copy constructor	
	
	//canonical form destructor
	~Fixed( void ); 
	
	Fixed&	operator=(const Fixed& rhs);
	
	//comparison operators
	bool	operator>( const Fixed& rhs ) const;
	bool	operator<( const Fixed& rhs ) const;
	bool	operator>=( const Fixed& rhs ) const;
	bool	operator<=( const Fixed& rhs ) const;
	bool	operator==( const Fixed& rhs ) const;
	bool	operator!=( const Fixed& rhs ) const;

	//arithmetic operators
	Fixed	operator+( const Fixed& rhs ) const;
	Fixed	operator-( const Fixed& rhs ) const;
	Fixed	operator*( const Fixed& rhs ) const;
	Fixed	operator/( const Fixed& rhs ) const;
	
	//increment/decrement operators
	Fixed&	operator++( void );
	Fixed	operator++( int );
	Fixed&	operator--( void );
	Fixed	operator--( int );

	//member functions 
	int getRawBits( void ) const; //returns the raw value of the fixed-point value
	void setRawBits( int const raw);; //sets the raw value of the fixed-point number 
	float toFloat( void ) const; //converts the fixed-point value to a floating-point value
	int toInt( void ) const; //converts the fixed-point value to an integer value

	//static member functions overload
	static Fixed& min( Fixed& nbrA, Fixed& nbrB );
	static Fixed& max( Fixed& nbrA, Fixed& nbrB );
	static const Fixed&	min( const Fixed& nbrA, const Fixed& nbrB );
	static const Fixed&	max( const Fixed& nbrA, const Fixed& nbrB );
};

std::ostream& operator<<( std::ostream& o, const Fixed& rhs );

#endif
