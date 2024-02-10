/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:32:14 by btani             #+#    #+#             */
/*   Updated: 2024/01/19 14:53:40 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void )
{
    Harl harl;
    std::string level;

    while (level.compare("EXIT"))
    {
        std::cout << std::endl;
		std::cout << "Enter one of these level: DEBUG, INFO, WARNING and ERROR or enter EXIT to quit the program" << std::endl;
        std::cout << std::endl;
		std::getline(std::cin, level);
		if(std::cin.eof() || level.compare("EXIT") == 0)
		{
			std::cout << std::endl;
			exit (1);
		}
        else if (level.compare("DEBUG") || level.compare("INFO") ||
                     level.compare("WARNING") || level.compare("ERROR"))
		        harl.complain(level);
        else				
			std::cout << "Error : invalid command" << std::endl;
    }
    return 0;
}	
