/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:28:08 by btani             #+#    #+#             */
/*   Updated: 2024/03/03 12:08:37 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void)
{
	{
		Array<int> intSlot(4);
		std::cout << "INT TEST" << std::endl;
		std::cout << std::endl;
		
		std::cout << "Given slot: " << std::endl;
		for (unsigned int i = 0; i < intSlot.size(); i++)
		{
			intSlot[i] = i;
			std::cout << intSlot[i] << std::endl;
		}	
		std::cout << std::endl;
		
		std::cout << "After process: " << std::endl;
		for (unsigned int i = 0; i < intSlot.size(); i++)
			intSlot[i] = i;
		for (unsigned int i = 0; i < intSlot.size(); i++)
			std::cout << intSlot[i] << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "STRING TEST" << std::endl;
		std::cout << std::endl;
		
		Array<std::string> stringSlot(4);
		std::cout << "Given slot: " << std::endl;
		for (unsigned int i = 0; i < stringSlot.size(); i++)
		{
			stringSlot[i] = "btani";
			std::cout << stringSlot[i] << std::endl;
		}
		
		std::cout << std::endl;
		std::cout << "After process: " << std::endl;
		for (unsigned int i = 0; i < stringSlot.size(); i++)
			stringSlot[i] = "btani";
		for (unsigned int i = 0; i < stringSlot.size(); i++)
			std::cout << stringSlot[i] << std::endl;	
		return 0;
	}
}


//SUBJECT MAIN
/*#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}*/
