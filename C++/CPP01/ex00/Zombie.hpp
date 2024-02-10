/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:45:25 by btani             #+#    #+#             */
/*   Updated: 2023/12/01 17:59:55 by btani            ###   ########.fr       */
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
		Zombie( std::string name );
		~Zombie( void );
	
		void announce( void );
};

	Zombie* newZombie( std::string name );
	void randomChump( std::string name );
	
#endif
