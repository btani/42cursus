/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:22:39 by btani             #+#    #+#             */
/*   Updated: 2024/02/01 18:25:04 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) 
{
	this->_type = type;	
};

Weapon::~Weapon( void ) { };

const std::string& Weapon::getType( void ) const
{
	return (this->_type);
};

void Weapon::setType( std::string newType )
{
	this->_type = newType;
};
