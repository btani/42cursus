/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:29:24 by btani             #+#    #+#             */
/*   Updated: 2024/03/01 15:38:02 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

int main(void)
{
	int slot[] = {6, 3, 17, 9, 11};
	std::vector<int> vector(slot, slot + sizeof(slot) / sizeof(int));
	std::cout << std::endl;
	std::cout << "Success test:"<< std::endl;
	try
	{
		std::vector<int>::iterator i = easyfind(vector, 3);
		std::cout << "Integer " << *i << " found \033[1;32mOK\033[0m " << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Failure test:"<< std::endl;
	try
	{
		std::vector<int>::iterator a = easyfind(vector, 5);
		std::cout << "\033[Integer " << *a << " found 1;32mOK\033[0m " << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
