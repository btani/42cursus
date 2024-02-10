/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:45:07 by btani             #+#    #+#             */
/*   Updated: 2024/02/01 17:56:53 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	Zombie* newZomb; // instance instantiated
	
	std::cout << std::endl;
	std::cout << "Zombie allocated on stack" << std::endl;
	randomChump("Gigino");
	std::cout << std::endl;
	std::cout << "Zombie allocated on heap" << std::endl;
	newZomb = newZombie("Gigetto");
	newZomb->announce();
	delete newZomb;
	std::cout << std::endl;
	return (0);
}
