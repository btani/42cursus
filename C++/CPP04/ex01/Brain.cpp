/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:28:12 by btani             #+#    #+#             */
/*   Updated: 2024/01/19 16:58:59 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
};

Brain::Brain(const Brain& copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
};

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
};

Brain&	Brain::operator=(const Brain& op)
{
	std::cout << "Brain copy assignament operator called" << std::endl;
	if (this != &op)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = op._ideas[i];
	}
	return *this;
};

std::string	Brain::getIdea(int i) const
{
	return (this->_ideas[i]);
};

void Brain::setIdea(std::string smartIdea, int i)
{
	this->_ideas[i] = smartIdea;
};
