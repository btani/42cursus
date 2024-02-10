/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:00:32 by btani             #+#    #+#             */
/*   Updated: 2024/02/01 18:13:47 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iomanip>
# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string _name;
	
	public:
		Zombie( void ); //default constructor
		~Zombie( void );
	
		void announce( void );
		void setZombieName( std::string name );
};
	Zombie* zombieHorde( int N, std::string name );
	
#endif
