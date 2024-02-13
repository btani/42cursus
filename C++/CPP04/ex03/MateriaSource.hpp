/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:43:10 by btani             #+#    #+#             */
/*   Updated: 2024/02/13 14:38:28 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
	
	AMateria* _inventory[4];
	
	public:
	
	MateriaSource(void);
	MateriaSource(const MateriaSource& copy);
	~MateriaSource(void);
	
	MateriaSource& operator=(const MateriaSource& op);

	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const& type);	
};

#endif
