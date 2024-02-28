/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:12:51 by btani             #+#    #+#             */
/*   Updated: 2024/02/21 19:43:34 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
	private:
	std::string _target;
	
	public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const& copy);
	~PresidentialPardonForm(void);
	
	PresidentialPardonForm& operator=(PresidentialPardonForm const& op);
	
	static AForm* createForm(const std::string& formTarget);
	void execute(Bureaucrat const& executor) const;
};
