/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:14:33 by btani             #+#    #+#             */
/*   Updated: 2024/01/24 17:18:56 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat:  public AAnimal
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
