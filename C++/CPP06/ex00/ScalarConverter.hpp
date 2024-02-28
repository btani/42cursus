/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:08:35 by btani             #+#    #+#             */
/*   Updated: 2024/02/23 19:28:25 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <limits>
# include <sstream>
# include <iomanip>
# include <cmath>


class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const& copy);	
		~ScalarConverter(void);

		ScalarConverter& operator=(ScalarConverter const& op);	

	public:	

		typedef enum e_type
		{
			CHAR, INT, FLOAT, DOUBLE, PSEUDO, UNKNOWN
		} selection;
		//CONVERTER
		//takes as parameter a string representation of a C++ literal;
		static void	convert(std::string literal);
		static selection whichType(const std::string& input);
		
		//CHECKERS		
		static bool checkisChar(std::string const& input);
		static bool checkisInt(std::string const& input);
		static bool checkisFloat(std::string const& input);
		static bool checkisDouble(std::string const& input);	

		//PRINTERS		
		static void convertChar(std::string const& input);
		static void convertInt(std::string const& input);
		static void convertFloat(std::string const& input);
		static void convertDouble(std::string const& input);
		static void convertPseudo(std::string const& input);
};
#endif 
