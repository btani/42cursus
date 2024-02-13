/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:41:58 by btani             #+#    #+#             */
/*   Updated: 2024/02/13 15:48:26 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter
{
	private:

	std::string _name;
	AMateria* _inventory[4];
	AMateria* _rest[15];
	
	public:

	Character(void);
	Character (const std::string& name);
	Character(const Character& copy);
	~Character(void);

	Character& operator=(const Character& op);

	virtual std::string const& getName(void) const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);	
};

#endif
