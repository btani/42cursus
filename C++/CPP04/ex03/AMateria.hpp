/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:13:18 by btani             #+#    #+#             */
/*   Updated: 2024/02/10 17:02:19 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP //the A stay fo abstract,is a convention for abstract class
# define AMATERIA_HPP
# include <iostream>
# include <string>
# include "ICharacter.hpp"

class	ICharacter;
class AMateria
{
	protected:

	std::string _materiaType;
	
	public:	

	AMateria(void);
	AMateria(std::string const& type);
	AMateria(const AMateria& copy);
	virtual ~AMateria(void);
	
	AMateria& operator=(const AMateria& op);
	
	std::string const& getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0; //pure method =0 means that ther is no defifinition for the method, no implementation
	virtual void use(ICharacter& target);
};

#endif
