/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:40:00 by btani             #+#    #+#             */
/*   Updated: 2024/02/07 15:58:28 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
	
	Cure(void);
	Cure(const Cure& copy);
	~Cure(void);
	
	Cure& operator=(const Cure& op);
	
	virtual AMateria* clone(void) const;
	virtual void use(ICharacter& target);
};

#endif
