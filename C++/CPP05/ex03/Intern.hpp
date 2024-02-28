/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:26:05 by btani             #+#    #+#             */
/*   Updated: 2024/02/21 19:51:16 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <fstream>
# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
	Intern(void);
	Intern(const Intern& copy);
	~Intern(void);
	
	Intern& operator=(Intern const& op);
	
	AForm* makeForm(const std::string& formName, const std::string& formTarget) const;
};

#endif
