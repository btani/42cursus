/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:41:07 by btani             #+#    #+#             */
/*   Updated: 2024/03/03 11:08:20 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
	std::cout << "Testing INT" << std::endl;
	int a = 2;
	int b = 3;
	std::cout << "Initial values: " << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "Swapped values: " << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << min(a, b) << std::endl; //implicit instansiation
	std::cout << "max(a, b) = " << max(a, b) << std::endl;

	std::cout << std::endl;

	std::cout << "Testing STRING" << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "Initial values: " << "c = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "Swapped values: " << "c = " << c << ", d = " << d << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << min(c, d) << std::endl;
	std::cout << "max(c, d) = " << max(c, d) << std::endl;
	
	return (0);
}
