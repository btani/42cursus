/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:23:33 by btani             #+#    #+#             */
/*   Updated: 2024/02/01 18:27:36 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB( std::string name)
{
	this->_nameB = name;
	this->_weapon = NULL; //weapon can be NULL
};

HumanB::~HumanB( void ) { };

void HumanB::setWeapon( Weapon& weapon )
{
	this->_weapon = &weapon; //pointer to a Weapon since the field is not set at creation time
};

void HumanB::attack( void )
{
	if (!this->_weapon)
		std::cout << _nameB << " attacks without weapons, using olny their hands!" << std::endl;
	else
		std::cout << _nameB << " attacks with their " << this->_weapon->getType() << std::endl;
};
