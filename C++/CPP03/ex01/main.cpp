/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:02:17 by btani             #+#    #+#             */
/*   Updated: 2024/02/05 19:24:55 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap scav("Ash");

	scav.printValues();
	scav.attack("Team Roket");
	scav.takeDamage(90);
	scav.beRepaired(70);
	scav.guardGate();	
		
	std::cout << std::endl;
	
	return 0;
}
