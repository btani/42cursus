/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:11:32 by btani             #+#    #+#             */
/*   Updated: 2024/02/13 14:52:54 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
	
	std::string _type;
	
	public:
	
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& copy);
	virtual ~WrongAnimal(void);

	WrongAnimal& operator=(const WrongAnimal& op);
	
	std::string getType(void) const;
	void makeSound(void) const;
};

#endif
