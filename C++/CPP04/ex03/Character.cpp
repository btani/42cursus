/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:42:13 by btani             #+#    #+#             */
/*   Updated: 2024/02/13 14:28:55 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
//deep copy: it makes a full copy of an object, including the objects pointed to by the original one

Character::Character(void): _name("name")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		this->_rest[i] = NULL;
	}
};

Character::Character(const std::string& name): _name(name)		
{
	std::cout << "Character param constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		this->_rest[i] = NULL;
	}	
};

Character::Character(const Character& copy)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = copy;
};

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;	
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		if (this->_rest[i] != NULL)
			delete this->_rest[i];
	}
};

Character& Character::operator=(const Character& op)
{
	std::cout << "Character copy assignament operator called" << std::endl;
	if (this != &op)
	{
		this->_name = op.getName();
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			this->_inventory[i] = op._inventory[i]->clone();
		}
	}
	return *this;
};

std::string const& Character::getName(void) const
{
	return this->_name;
};

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
				this->_inventory[i] = m;
				return ;
		}
		else
			std::cout << "Tryng to add Materia to a full inventory!" << std::endl;
	}
};

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Wrong index!" << std::endl;
		return ;
	}
	else if (this->_inventory[idx] != NULL)
		this->_inventory[idx] = NULL;
	else
		std::cout << "Tryng to unequip an existing Materia, but inventory is empty!" << std::endl;
};

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Wrong index!" << std::endl;
		return ;
	}
	else if (this->_inventory[idx] != NULL)
		(*this->_inventory[idx]).use(target);
	else
		std::cout << "Tryng to use an existing Materia, but inventory is empty!" << std::endl;
};
