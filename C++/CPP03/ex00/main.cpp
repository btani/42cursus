/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:46:32 by btani             #+#    #+#             */
/*   Updated: 2024/02/05 18:40:03 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap name("Ash");

	name.printValues();
	name.setAttackDamage(3);
	name.attack("Team Roket");
	name.takeDamage(9);
	name.beRepaired(11);
	name.takeDamage(2);	
	name.beRepaired(11);
		
	std::cout << std::endl;

	name.printValues();
	
	return 0;
}
