/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:11:32 by btani             #+#    #+#             */
/*   Updated: 2024/01/24 16:26:02 by btani            ###   ########.fr       */
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
	virtual void makeSound(void) const;
};

#endif
