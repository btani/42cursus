/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:56:44 by btani             #+#    #+#             */
/*   Updated: 2024/03/14 19:41:18 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <iostream>
# include <algorithm>
# include <exception>
# include <iterator>
# include <limits>
# include <numeric>
# include <time.h>


class Span
{
	private:
		std::vector<int> _vec;
		unsigned int _maxLen;
			
	public:
		Span(void);
		Span(unsigned int N);
		Span(Span const& copy);
		~Span(void);
		
		Span& operator=(Span const& op);
		
		void addNumber(int singleNbr);
		int shortestSpan();
		int longestSpan();
		
		/*
		STL algorithm used is std::distance(),that calculates the number of elements in the range
		defined by the two iterators.It returns the number of elements between the two iterators.
		Here used to determine the number of elements in the range (begin, end) and compare it with _maxLen.
		*/
		template <typename Iter>
		void useRangeIterators(Iter begin, Iter end)
		{
			if (_vec.size() == _maxLen)	
				throw FullSpanException();
			else if (std::distance(begin, end) <= _maxLen)
				_vec.assign(begin, end);
			else
				_vec.assign(begin, begin + _maxLen - _vec.size());
				std::cout << "Span is filled with " << _vec.size() << " numbers." << std::endl;
				throw FullSpanException();
		}
		
		class FullSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "The Span is full. \033[1;35mKO\033[0m";
				}
		};
		
		class SpanNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Not enough numbers stored. No Span can be found. \033[1;35mKO\033[0m";
				}
		};
};

#endif

/*
range of itarators: a pair of iterators pointing to first and last elements of a sequence;
the sequence can be a part of a container(like an array, vector, list, etc.) or the entire container itself
beginning iterator points to the first element, end iterator points one past the last element.
is a half-open range, which means it includes the first element but not the last one.
*/
