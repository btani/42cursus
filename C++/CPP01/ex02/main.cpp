/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:00:18 by btani             #+#    #+#             */
/*   Updated: 2024/02/01 18:23:17 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iomanip>
# include <iostream>
# include <string>

int	main( void )
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;
	
	std::cout << std::endl;
	std::cout << "Memory address displayed using the string vrb: " << &str << std::endl;
	std::cout << "Memory address displayed using the stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address displayed using the stringREF: " << &stringREF << std::endl;
	
	std::cout << std::endl;
	std::cout << "Stirng: " << str << std::endl;
	std::cout << "Stirng using pointer: " << *stringPTR << std::endl;
	std::cout << "Stirng using reference: " << stringREF << std::endl;
	
	std::cout << std::endl;
	
	return (0);
}
