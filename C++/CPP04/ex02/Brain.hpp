/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:28:35 by btani             #+#    #+#             */
/*   Updated: 2024/01/24 16:25:10 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>

class Brain
{
	protected:
	
	std::string _ideas[100];
	
	public:
	
	Brain(void);
	Brain(const Brain& copy);
	~Brain(void);

	Brain& operator=(const Brain& op);

	std::string getIdea(int i) const;
	void setIdea(std::string smartIdea, int i);

};

#endif
