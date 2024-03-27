/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:56:55 by btani             #+#    #+#             */
/*   Updated: 2024/03/14 19:42:29 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span(void) : _maxLen(0) {}

Span::Span(unsigned int N) : _maxLen(N) {}

Span::Span(Span const& copy)
{
	*this = copy;
}

Span::~Span(void) {}

Span& Span::operator=(Span const& op)
{
	if (this != &op)
	{
		_maxLen = op._maxLen;
		_vec = op._vec;
	}
	return *this;
}

void Span::addNumber(int singleNbr)
{
	std::vector<int>::iterator it = std::find(_vec.begin(), _vec.end(), singleNbr);
	if (_vec.size() < _maxLen)
	{
		_vec.push_back(singleNbr);
	}
	else
	{
		throw FullSpanException();
	}
}

/*
std::adjacent_difference(): used to compute the difference between each pair of adjacent elements in a range.
result is written to another range, beginning at the location pointed to by the output iterator.
It computes the difference between each element and writes the result to the vector result
*/
int Span::shortestSpan()
{
	if (this->_vec.size() < 2)
	{
		throw SpanNotFoundException();
	}
	int diffRange[this->_vec.size()];
	std::adjacent_difference(_vec.begin(), _vec.end(), diffRange);
	std::vector<int> result;
	for (int i = 0; i < this->_vec.size(); i++)
	{
		if (diffRange[i] >= 0)
			result.push_back(diffRange[i]);
	}
	return *std::min_element(result.begin(), result.end());
}

int Span::longestSpan()
{
	if (this->_vec.size() < 2)
	{
		throw SpanNotFoundException();
	}
	return *std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end());
}
