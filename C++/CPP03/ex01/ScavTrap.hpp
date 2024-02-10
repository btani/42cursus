/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:44:59 by btani             #+#    #+#             */
/*   Updated: 2024/01/12 17:41:47 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
	
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& copy);
	~ScavTrap(void);

    ScavTrap& operator=(const ScavTrap& op);

	unsigned int getAttackDamage(void) const;
	void setAttackDamage(unsigned int attackDamage);
	void attack(const std::string& target);
	void guardGate(void);
};
