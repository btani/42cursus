/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:14:33 by btani             #+#    #+#             */
/*   Updated: 2024/01/23 16:32:12 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

class Cat:  public Animal
{
	private:
	
	Brain* _brain;
	
	public:
	
	Cat(void);
	Cat(const Cat& copy);
	~Cat(void);

	Cat& operator=(const Cat& op);
	
	virtual void makeSound(void) const;
};
