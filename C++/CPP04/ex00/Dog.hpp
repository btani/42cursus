/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:14:25 by btani             #+#    #+#             */
/*   Updated: 2024/01/15 17:54:48 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog:  public Animal
{
	protected:
	
	std::string _type;
	
	public:
	
	Dog(void);
	Dog(const Dog& copy);
	virtual ~Dog(void);
	
	Dog& operator=(const Dog& op);

	virtual void makeSound(void) const;
};
