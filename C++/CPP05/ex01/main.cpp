/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:11:31 by btani             #+#    #+#             */
/*   Updated: 2024/02/18 15:11:32 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat bureaucrat("The employee", 20);
	std::cout << std::endl;
	Form form("Application form", 1, 30);
	std::cout << std::endl;
	bureaucrat.signForm(form);
	std::cout << std::endl;
	std::cout << form << std::endl;

	return 0;
}
