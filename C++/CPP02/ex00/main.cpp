/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:42:26 by btani             #+#    #+#             */
/*   Updated: 2024/01/19 15:05:55 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Default constructor: Creates an object without initializing its data members.
Copy constructor: Creates an object by copying the content of another object of the same type.
If a class has data members that are pointers, you should implement the copy constructor.
If you don't, the default copy constructor will copy an object by copying the values of the data members,just the addresses for pointers will be copied
Copy assignment operator: Assigns the content of another object of the same type to the current object.
fixed-point number: in numerical data, a decimal number is represented by an integral part and a fractional part,
with a fixed number of decimal places to the right of the decimal point. They maintain a fixed number of decimal positions,
regardless of the magnitude of the number itself."*/
#include "Fixed.hpp"

int main( void )
{
	Fixed a; //Default constructor called
	Fixed b( a ); //Copy constructor called
	Fixed c; //Default constructor called
	
	c = b; //Assignation operator called
	
	//member function called
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return 0;
}
