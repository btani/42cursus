/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:00:18 by btani             #+#    #+#             */
/*   Updated: 2024/02/01 18:18:21 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie* zbHorde;
	int N = 10;

	std::cout << std::endl;
	std::cout << "Creating a horde: adding " << N << " zombies" << std::endl;
	std::cout << "Loading..." << std::endl;
	zbHorde = zombieHorde(N, "Franco");
	for (int i = 0; i < N; i++)
		zbHorde[i].announce();
	std::cout << std::endl;
	std::cout << "Destroying the horde of zombies created" << std::endl;
	std::cout << "Loading..." << std::endl;
	delete[] zbHorde; //all zombies deleted at the same time
	std::cout << std::endl;
	return (0);
}
