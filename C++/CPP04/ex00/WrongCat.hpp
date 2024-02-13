/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:12:02 by btani             #+#    #+#             */
/*   Updated: 2024/02/13 15:04:39 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

class WrongCat:  public WrongAnimal
{
	protected:
	
	std::string _type;
	
	public:
	
	WrongCat(void);
	WrongCat(const WrongCat& copy);
	virtual ~WrongCat(void);

	WrongCat& operator=(const WrongCat& op);
	
	void makeSound(void) const;
};

