/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:23:27 by btani             #+#    #+#             */
/*   Updated: 2023/12/06 18:30:59 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
	private:
	
		std::string _nameB;
		Weapon* _weapon;

	public:
	
		HumanB( std::string _nameB );
		~HumanB( void );
		
		void attack( void );
		void setWeapon( Weapon& weapon );	
};

#endif
