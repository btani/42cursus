/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:37:22 by btani             #+#    #+#             */
/*   Updated: 2024/02/10 17:01:49 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include <iostream>

class AMateria;
class IMateriaSource
{
	public:
	
	virtual ~IMateriaSource(void) {};
	
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif
