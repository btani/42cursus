/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:45:49 by btani             #+#    #+#             */
/*   Updated: 2024/02/01 18:03:55 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
-try-catch: used for exception handling, it allows to handle 
errors/unexpected situations without the program terminate abruptly. 
-std::bad_alloc&: signal memory allocation errors (here used to 
prevent that memory allocation operator("new") fail to allocate dynamic memory).
-std::cerr: unbuffered standard error stream (data is written immediately to the output)
*/
Zombie* newZombie( std::string name )
{
	Zombie* newZomb;
	
	try
	{
		newZomb = new Zombie(name); // condition that might throw an exception
	}
	catch (const std::bad_alloc& err) 
	{
		std::cerr << "Exception caught: " << err.what() << std::endl; // handle the exception
		newZomb = NULL;
	}
	return newZomb;
};
