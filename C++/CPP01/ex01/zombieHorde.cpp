/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:01:07 by btani             #+#    #+#             */
/*   Updated: 2024/02/01 18:17:14 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// returns a pointer to the first zombie
Zombie* zombieHorde( int N, std::string name )
{
	Zombie* zombie;
	
	try
	{
		zombie = new Zombie[N]; //N zombie allocated in a single allocation

	}
	catch (const std::bad_alloc& err) 
	{
		std::cerr << "Exception caught: " << err.what() << std::endl;
		zombie = NULL;
	}
	for(int i = 0; i < N; i++)
	{
		zombie[i].setZombieName(name); //initialize zombies, naming it with name passed as parameter

	}
	return zombie;	//returns a pointer to the first zombie

};
