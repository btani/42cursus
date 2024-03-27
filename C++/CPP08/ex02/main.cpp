/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:00:59 by btani             #+#    #+#             */
/*   Updated: 2024/03/22 20:38:14 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <stack>
#include <iostream>
#include <iterator>

//pdf main
int main()
{
	MutantStack<int> mstack;
	
	std::cout << "\033[1;32mRunning MutantStack: \033[0m pushing 5 and 17\n";
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << " is on the top of the stack" << std::endl;
	std::cout << "Stack size: " << mstack.size() << std::endl;	
	std::cout << "\033[1;32mPopped the element on the top of the stack\033[0m" << std::endl;		
	mstack.pop();
	std::cout << "New stack size: " << mstack.size() << std::endl;
	std::cout << "\033[1;32mRunning MutantStack with moooore elements\033[0m\n";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mstack.push(-10);
	mstack.push(11);
	std::cout << mstack.top() << " is on the top of the stack" << std::endl;
	std::cout << "Stack size: " << mstack.size() << std::endl;	
	std::cout << "\033[1;32mPopped the element on the top of the stack\033[0m" << std::endl;	
	mstack.pop();
	std::cout << "New stack size: " << mstack.size() << std::endl;
	mstack.push(4);
	mstack.push(-500);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);


	return 0;
}

/*
From subject:
run the main and a second time replacing the MutantStack with, for example, a std::list.
the two outputs should be the same.
*/
/*int main() 
{
    std::list<int> mstack;
    
   	std::cout << "\033[1;32mRunning std::list: \033[0m pushing 5 and 17\n";
    mstack.push_back(5);
    mstack.push_back(17);
	std::cout << "List size: " << mstack.size() << std::endl;	
	std::cout << "\033[1;32mPopped the element on the top of the list\033[0m" << std::endl;
    mstack.pop_back();
	std::cout << "New list size: " << mstack.size() << std::endl;
	std::cout << "\033[1;32mRunning std::list with moooore elements\033[0m\n";
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);
    mstack.push_back(-10);
	mstack.push_back(11);
	std::cout << "List size: " << mstack.size() << std::endl;	
	std::cout << "\033[1;32mPopped the element on the top of the list\033[0m" << std::endl;	
	mstack.pop_back();
	std::cout << "New list size: " << mstack.size() << std::endl;
	mstack.push_back(4);
	mstack.push_back(-500);
	
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int, std::list<int>> s(mstack);

    return 0;
}*/
