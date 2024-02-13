/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:13:02 by btani             #+#    #+#             */
/*   Updated: 2024/01/24 18:15:41 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>
# include <string>

class AAnimal
{
	protected:
	
	std::string _type;
	
	public:
	
	AAnimal(void);
	AAnimal(const AAnimal& copy);
	virtual ~AAnimal(void);

	AAnimal& operator=(const AAnimal& op);
	
	std::string getType(void) const;
	virtual void makeSound(void) const = 0; //pure virtual method
};

#endif
