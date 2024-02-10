/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:22:22 by btani             #+#    #+#             */
/*   Updated: 2024/01/19 14:53:03 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream> 
# include <iomanip>  
# include <string>

class Weapon
{
	private:

		std::string _type;
	
	public:	

		Weapon( std::string _type );
		~Weapon( void );
	
		const std::string& getType( void ) const;
		void setType( std::string newType );
};

#endif
