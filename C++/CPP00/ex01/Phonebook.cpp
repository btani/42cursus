/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:44:39 by btani             #+#    #+#             */
/*   Updated: 2023/12/12 15:56:21 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Phonebook.hpp"

int PhoneBook::_add = 0;
PhoneBook::PhoneBook(void)
{
	this->_max_value = 0;
	
};

PhoneBook::~PhoneBook(void) { };

void PhoneBook::addCont(void)
{
	if (this->_add == 8)
		this->_add = 0;
	_contacts[this->_add].setValue(_contacts[this->_add]);
	this->_add++;
	if (this->_max_value <= 7)
		this->_max_value++;
	
};

//getline(): to read a line from standard input
//c_str: returns a pointer to an array that contains a null-terminated
//sequence of characters representing the current value of the string object.
void PhoneBook::searchCont(void)
{
	std::string index_to_search;
	int			index_as_num;

	std::cout << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "|  INDEX  |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
   	std::cout << "--------------------------------------------" << std::endl;
	_contacts[1].displayList(getContact(), _max_value);
	std::cout << std::endl;
	std::cout << "Insert index :";
	std::getline(std::cin, index_to_search);
	if (std::cin.eof())
		exit(1);
	index_as_num = atoi(index_to_search.c_str());
	if (index_as_num > 0 && index_as_num <= _max_value)
	{
		_contacts[index_as_num - 1].displayCont();
		std::cout << std::endl;
	}
	else if (std::cin.eof())
		return ;
	else
	{	
		std::cout << std::endl;
		std::cout << "Invalid index : no contact information" << std::endl;
		std::cout << std::endl;
	}
};

Contact *PhoneBook::getContact()
{
	return (_contacts);
};
