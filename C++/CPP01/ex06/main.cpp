/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:33:34 by btani             #+#    #+#             */
/*   Updated: 2024/02/02 15:34:59 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


//Program takes as parameter one of the four levels and display all messages from here and above
int main( int ac, char **av )
{
    Harl harl;    

    if (ac != 2)
    {
		std::cout << "[ Silence... ]" << std::endl;
		return 1;
	}
    std::string level = av[1];
    harl.complain(level);
    return 0;
}	
