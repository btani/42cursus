/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:10:44 by btani             #+#    #+#             */
/*   Updated: 2024/02/23 19:15:09 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "\033[1;35mError: invalid arguments.\033" << std::endl;;
		return 1;
	}
	else
		ScalarConverter::convert(av[1]);
	return 0;
}
