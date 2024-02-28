/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:13:08 by btani             #+#    #+#             */
/*   Updated: 2024/02/18 18:03:10 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
	private:
	std::string _target;
	
	public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const& copy);
	~RobotomyRequestForm(void);
	
	RobotomyRequestForm& operator=(RobotomyRequestForm const& op);
	
	void execute(Bureaucrat const& executor) const;
};


