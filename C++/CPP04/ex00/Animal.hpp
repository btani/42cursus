/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:13:02 by btani             #+#    #+#             */
/*   Updated: 2024/01/15 17:02:39 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

class Animal
{
	protected:
	
	std::string _type;
	
	public:
	
	Animal(void);
	Animal(const Animal& copy);
	virtual ~Animal(void);

	Animal& operator=(const Animal& op);
	
	std::string getType(void) const;
	virtual void makeSound(void) const;
};

#endif
