/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:13:23 by btani             #+#    #+#             */
/*   Updated: 2024/02/21 19:43:44 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
	std::string _target;

	public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const& copy);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& op);
	
	static AForm* createForm(const std::string& formTarget);
	void execute(Bureaucrat const& executor) const;
};

