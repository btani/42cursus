/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:27:54 by btani             #+#    #+#             */
/*   Updated: 2024/03/03 12:02:39 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <exception>
# include <stdlib.h>

template <typename T>
class Array
{
    private:
		T* _arr;
		unsigned int _len;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& copy);
		~Array(void);
		
		Array<T>& operator=(const Array& op);
		T& operator[](unsigned int i);
		unsigned int size(void) const;

		class OutofBoundsException : public std::exception
		{
			public:
				const char* what( ) const throw ( ) {
					return ("Idenx out of bound");
				};
		};
		
};

#include "Array.tpp"

/* creation of aclass template that behaves like an array*/
