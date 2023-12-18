/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:55:17 by btani             #+#    #+#             */
/*   Updated: 2023/12/12 17:43:31 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char *av[])
{
	std::string str;
	int i;
	int j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (i =  1; i < ac; i++)
			for (j = 0; av[i][j] != '\0'; j++)
				std::cout << (char)toupper(av[i][j]);
	}
	std::cout << std::endl;
	return (0);
}	
