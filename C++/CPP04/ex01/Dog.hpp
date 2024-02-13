/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:14:25 by btani             #+#    #+#             */
/*   Updated: 2024/01/23 16:32:29 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
	
	Brain* _brain;
	
	public:
	
	Dog(void);
	Dog(const Dog& copy);
	~Dog(void);
	
	Dog& operator=(const Dog& op);

	virtual void makeSound(void) const;
};
