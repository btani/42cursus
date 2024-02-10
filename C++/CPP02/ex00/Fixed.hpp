/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:42:54 by btani             #+#    #+#             */
/*   Updated: 2024/02/03 18:25:10 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:
	
	int _fixedNbr;
	static const int _fractBits = 8;

	public:
	
	Fixed( void ); //canonical form constructor
	Fixed( const Fixed& src ); //canonical form copy constructor
	
	~Fixed( void ); //canonical form destructor
	
	Fixed& operator=( const Fixed& rhs ); // rhs = right hand side /copy assignment operator
	 
	int getRawBits( void ) const; //returns the raw value of the fixed-point value
	void setRawBits( int const raw);; //sets the raw value of the fixed-point number 
	
};

#endif

