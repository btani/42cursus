/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:23:09 by btani             #+#    #+#             */
/*   Updated: 2024/02/01 18:27:52 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon) : _weapon(weapon)
{
	this->_nameA = name;	
};

HumanA::~HumanA( void ) { };

void HumanA::attack( void)
{
	std::cout << _nameA << " attacks with their " << _weapon.getType() << std::endl;
};
