/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:29:42 by btani             #+#    #+#             */
/*   Updated: 2024/03/14 19:37:08 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

class NotFoundException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Integer not found \033[1;35mKO\033[0m";
	}
};

/*scope: find the first occurrence of the second parameter in the first parameter
STL algorithm used is std::find(), that searches for the first occurrence of a 
specified value within the given range. It returns an iterator to the found element if it exists,
 or the end iterator if the element is not found.
*/
template <typename T>
typename T::iterator easyfind(T& container, int integer) //T is a container of integer
{
	typename T::iterator iter = find(container.begin(), container.end(), integer);
	if (iter == container.end() || *iter != integer)
		throw NotFoundException();
	else
		return (iter);
}


/*
STL (Standard Template Library) algorithms are a set of functions provided 
by the C++ Standard Library for performing operations on containers like vectors, lists, sets, maps, etc. These algorithms are designed to work with iterators,
providing a generic interface for performing common tasks efficiently
containers: predefined or customized data structures to store and organize elements of the
same type efficiently. They provide an interface for accessing/manipulating/managing data in memory.
sequence containers: they store elements in a linear sequence
-Array: a sequence of elements of the same type, accessible via a numerical index. 
		Arrays have a fixed size specified during declaration.
-Vector: a dynamic data structure that automatically expand to accommodate new elements,
		 its size can vary dynamically.			
-List: a sequence of elements linked via pointers, where the order of elements is maintained.
		Lists allow efficient insertion and removal of elements at any position.
associative containers: they store elements in a way that supports quick retrieval
-Map: a data structure that associates keys with values. Each element of the map is 
		a unique key-value pair, where the key is used to access the associated value.
*/

