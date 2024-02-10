/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:22:57 by btani             #+#    #+#             */
/*   Updated: 2023/12/06 16:57:19 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
	private:
	
		std::string _nameA;
		Weapon& _weapon;

	public:;
	
		HumanA( std::string _nameA, Weapon& _weapon );
		~HumanA( void );
		
		void attack( void );	
};

#endif
