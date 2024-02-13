/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:42:39 by btani             #+#    #+#             */
/*   Updated: 2024/02/12 16:28:41 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP //the I stay fo interface,is a convention for interface class
# define ICHARACTER_HPP
# include <iostream>
# include "AMateria.hpp"

class AMateria;
class ICharacter
{
	public:

	virtual ~ICharacter(void) {};
	virtual std::string const& getName(void) const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif
