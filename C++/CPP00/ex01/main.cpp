/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:44:07 by btani             #+#    #+#             */
/*   Updated: 2023/12/12 17:30:27 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

/*
eof(): checks if the end-of-file (EOF) has been reached on the standard
input stream (std::cin). The eof() function returns true if the end of the
file has been reached
compare(): function used to compare two strings, is used to check 
the lexicographical (dictionary) order of two strings
*/
int main(int ac, char **av)
{
	(void) av;
	PhoneBook phoneBook;
	std::string str;

	if (ac == 1)
		{
			while (1)
			{
				std::cout << std::endl;
				std::cout << "Enter one of these three commands ADD-SEARCH-EXIT : "; 
				std::getline(std::cin, str);
				if (str.compare("EXIT") == 0)
					exit(1);
				else if (str.compare("ADD") == 0)
					phoneBook.addCont();
				else if (str.compare("SEARCH") == 0)
					phoneBook.searchCont();
				else if (std::cin.eof())
					exit(1);
				else
				{
					std::cout << std::endl;				
					std::cout << "Error : invalid command" << std::endl;
				}		
			}
	}
	else
		std::cout << "Error : Invalid number of arguments" << std::endl;
	return (0);
}
