/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:59:10 by btani             #+#    #+#             */
/*   Updated: 2024/02/04 18:24:12 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << std::endl;
	std::cout << "Incrementation of a: " << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl; //pre-incrementation
	std::cout << a << std::endl;
	std::cout << a++ << std::endl; //post-incrementation
	std::cout << a << std::endl;
	std::cout << std::endl;
	std::cout << "Decrementation of a: " << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl; //pre-decrementation
	std::cout << a << std::endl;
	std::cout << a-- << std::endl; //post-decrementation
	std::cout << a << std::endl;
	std::cout << std::endl;
	std::cout << "Operation with b: " << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;
	std::cout << "Max: " << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "Min: " << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	
	return 0;
}
