/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:00:11 by btani             #+#    #+#             */
/*   Updated: 2024/02/25 18:22:53 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
# include <iostream>
# include <time.h>

class Base
{
	public:
		virtual ~Base(void);
};

Base* generate(void);
void identify(Base* p);	
void identify(Base& p);	

#endif

//The four classes don’t have to be designed in the Orthodox Canonical Form.
