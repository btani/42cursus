/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:45:33 by btani             #+#    #+#             */
/*   Updated: 2023/12/01 21:16:28 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
	std::cout << "Constructor called" << std::endl;
	this->_name = name;
};

Zombie::~Zombie( void )
{
	std::cout << "Destructor called: " << this->_name << " zombie has been deleted, saaaaad :(" << std::endl;
}
void Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;	
};
