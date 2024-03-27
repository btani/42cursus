/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:01:14 by btani             #+#    #+#             */
/*   Updated: 2024/03/14 19:34:38 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stack>
# include <iostream>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void): std::stack<T>() {};
		MutantStack(MutantStack const& copy)
		{
			*this = copy;
		};
		virtual ~MutantStack(void) {};
		MutantStack& operator=(MutantStack const& op)
		{
			if (this != &op)
				this->c = op.c;
			return *this;
		};
	
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;		
	
		/*
		begin() const: Member function returns a const_iterator to the beginning/ending of the
		underlying container,but isn't guarantee that the iterator will point to a constant object.
		So the underlying object can be modified through the iterator if it is not a const object
		*/
		iterator begin() { return this->c.begin(); };
		iterator end() { return this->c.end(); };
		
		/*
		cbegin() const: member function returns a const_iterator to the beginning/ending of the 
		underlying container, it guarantees the iterator will point to a constant object.
		So the underlying object cannot be modified through the iterator.
		*/
		const_iterator cbegin() const { return this->c.cbegin(); }; //
		const_iterator cend() const { return this->c.cend(); };
		
		reverse_iterator rbegin() { return this->c.rbegin(); };
		reverse_iterator rend() { return this->c.rend(); }

		const_reverse_iterator crbegin() const { return this->c.crbegin(); };
		const_reverse_iterator crend() const { return this->c.crend(); }
		
};

/*
std::stack: container adapter that provides the functionality of a stack [Last-In, First-Out (LIFO)] data structure.
It's implemented on top of other container types and provides several methods for manipulating stacks:
push(g) : Adds the element 'g' at the top of the stack
pop() : Removes the top element of the stack
top() : Returns the top element of the stack
empty() : Returns whether the stack is empty
size() : Returns the size of the stack
*/
	
