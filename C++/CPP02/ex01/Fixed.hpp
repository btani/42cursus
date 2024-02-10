/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:32:30 by btani             #+#    #+#             */
/*   Updated: 2024/02/03 18:28:14 by btani            ###   ########.fr       */
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
	
	Fixed( void ); //canonical form constructor
	Fixed( const int nbr);
	Fixed( const float nbr);
	Fixed( const Fixed& src ); //canonical form copy constructor
	
	~Fixed( void ); //canonical form destructor
	
	Fixed& operator=( const Fixed& rhs ); // rhs = right hand side
	 
	int getRawBits( void ) const; //returns the raw value of the fixed-point value
	void setRawBits( int const raw);; //sets the raw value of the fixed-point number 
	float toFloat( void ) const; //converts the fixed-point value to a float value
	int toInt( void ) const; //converts the fixed-point value to an integer value
};

std::ostream& operator<<(std::ostream& o, const Fixed& rhs);

#endif
