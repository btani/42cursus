/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:33:20 by btani             #+#    #+#             */
/*   Updated: 2024/02/02 15:29:01 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) { };

Harl::~Harl( void ) { };

void	Harl::complain(std::string level)
{
	void (Harl::*complain[4])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	compLevel[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;

	while (i < 4)
	{
		if (!level.compare(compLevel[i]))
            break;
        i++;
	}
	switch (i)
	{
		case 0:
		{
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*complain[0])();
			std::cout << std::endl;
		}
		case 1:
		{
			std::cout << "[ INFO ]" << std::endl;
			(this->*complain[1])();
			std::cout << std::endl;
		}
		case 2:
		{
			std::cout << "[ WARNING ]" << std::endl;
			(this->*complain[2])();
			std::cout << std::endl;
		}
		case 3:
		{
			std::cout << "[ ERROR ]" << std::endl;
			(this->*complain[3])();
			std::cout << std::endl;
			break ;
		}
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
};

void	Harl::debug(void) 
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
};

void	Harl::info(void) 
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
};

void	Harl::warning(void) 
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
};

void	Harl::error(void) 
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
};
