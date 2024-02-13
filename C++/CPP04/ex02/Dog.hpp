/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:14:25 by btani             #+#    #+#             */
/*   Updated: 2024/01/24 17:24:37 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
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
