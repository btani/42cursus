/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:14:33 by btani             #+#    #+#             */
/*   Updated: 2024/01/15 17:02:27 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat:  public Animal
{
	protected:
	
	std::string _type;
	
	public:
	
	Cat(void);
	Cat(const Cat& copy);
	virtual ~Cat(void);

	Cat& operator=(const Cat& op);
	
	virtual void makeSound(void) const;
};
