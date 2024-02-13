/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:40:26 by btani             #+#    #+#             */
/*   Updated: 2024/02/10 16:56:42 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice: public AMateria
{
	public:

	Ice(void);
	Ice(const Ice& copy);
	~Ice(void);
	
	Ice& operator=(const Ice& op);
	
	virtual AMateria* clone(void) const;
	virtual void use(ICharacter& target);
};

#endif
