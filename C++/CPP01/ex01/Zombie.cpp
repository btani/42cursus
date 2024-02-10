/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:00:44 by btani             #+#    #+#             */
/*   Updated: 2024/02/01 18:13:54 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) { };

Zombie::~Zombie( void )
{
	std::cout << "Destructor called" << std::endl;
	std::cout << "Zombie named " << this->_name << " has been deleted, saaaaad :(" << std::endl;
};

void Zombie::setZombieName( std::string name )
{
	this->_name = name;
};

void Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;	
};
