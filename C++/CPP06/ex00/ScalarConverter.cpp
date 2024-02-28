/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:08:00 by btani             #+#    #+#             */
/*   Updated: 2024/02/25 19:02:54 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
};

ScalarConverter::ScalarConverter(ScalarConverter const& copy)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = copy;
};

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor called" << std::endl;
};

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& op)
{
	std::cout << "ScalarConverter assignation operator called" << std::endl;
	(void)op;
	return *this;
};

static bool num_controller(const std::string& input)
{
	int i = 0;
	
	if (i < input.length() && (input.at(i) == '-' || input.at(i) == '+'))
		i++;
	if (i < input.length() && std::isdigit(input.at(i)))
		while (i < input.length() && std::isdigit(input.at(i)))
			i++;
	else
		return false;
	if (i < input.length() && input.at(i) == '.')
	{
		i++;
		if (i < input.length() && std::isdigit(input.at(i)))
		{
			while (i < input.length() && std::isdigit(input.at(i)))
				i++;
		}
		else
			return false;
	}
	if (i < input.length() && input[i] == 'f')
		i++;
	return i == input.length();
};

ScalarConverter::selection ScalarConverter::whichType(const std::string& input)
{
	std::string pseudo[5] = {"-inf", "+inf", "-inff", "+inff", "nan"};
	selection type = UNKNOWN;
	
	if (num_controller(input))
	{
		if (input.find('f') != std::string::npos)
			return FLOAT;
		else if (input.find('.') != std::string::npos)
			return DOUBLE;
		return INT;
	}
	if(input.empty())
		type = UNKNOWN;
	if (checkisChar(input))
		type = CHAR;
	else if (num_controller(input))
	{
		if (checkisInt(input))
			type = INT;
		else if (checkisFloat(input))
		{
			if (!input.compare("nanf") || !input.compare("+inff") || !input.compare("-inff") || !input.compare("inff"))
				type = FLOAT;
		}
		else if (checkisDouble(input))
		{
			if (!input.compare("nan") || !input.compare("+inf") || !input.compare("-inf") || !input.compare("inf"))
				type = DOUBLE;
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
			if (pseudo[i] == input)
				type = PSEUDO;
	}
	return (type);
};

//CHECKERS
bool ScalarConverter::checkisChar(std::string const& input)
{
	if (input.length() != 1 || isdigit(input[0]))
		return (false);
	return (true);
};

bool ScalarConverter::checkisInt(std::string const& input)
{
	std::istringstream	toConvert(input);
	int	checkInput;

	toConvert >> checkInput;
	return (toConvert.eof() && !toConvert.fail());
};

bool ScalarConverter::checkisFloat(std::string const& input)
{
	std::string	inputCopy(input);
	float	checkInput;
	
	if (input[input.length() - 1] != 'f')
		return (false);
	else
		inputCopy == input.substr(0, input.length() - 1);

	std::istringstream	toConvert(inputCopy);
	toConvert >> checkInput;
	return (toConvert.eof() && !toConvert.fail());
};

bool ScalarConverter::checkisDouble(std::string const& input)
{
	std::istringstream	toConvert(input);
	double	checkInput;

	toConvert >> checkInput;
	return (toConvert.eof() && !toConvert.fail());
};

//PRINTERS
void ScalarConverter::convertChar(std::string const& input)
{
	char c = static_cast<char>(input.at(0));

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(c) << "f" << std::endl;;
	std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(c) << std::endl;
};

void ScalarConverter::convertInt(std::string const& input)
{
	std::istringstream	toConvert(input);
	int	i;

	toConvert >> i;
	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(i) << std::endl;
};

void ScalarConverter::convertFloat(std::string const& input)
{
	std::string	inputCopy = input.substr(0, input.length() - 1);
	std::istringstream	toConvert(inputCopy);
	float f;

	toConvert >> f;
	if (static_cast<int>(f) < 0 || static_cast<int>(f) > 127 || !input.compare("nanf"))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(f)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min() || !input.compare("nanf"))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(2) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(f) << std::endl;
};

void ScalarConverter::convertDouble(std::string const& input)
{
	std::istringstream	toConvert(input);
	double d;

	toConvert >> d;
	if (static_cast<int>(d) < 0 || static_cast<int>(d) > 127 || !input.compare("nanf"))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min() || !input.compare("nanf"))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << d << std::endl;
};

void ScalarConverter::convertPseudo(std::string const& input)
{
	if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (input == "+inf" || input == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
};

//CONVERTER
void ScalarConverter::convert(std::string const input)
{
	e_type	selection = whichType(input);
	switch (selection)
	{
		case CHAR:
			std::cout << "Input is a char" << std::endl;
			convertChar(input);
			break;
		case INT:
			std::cout << "Input is an int" << std::endl;
			convertInt(input);
			break;
		case FLOAT:
			std::cout << "Input is a float" << std::endl;
			convertFloat(input);
			break;
		case DOUBLE:
			std::cout << "Input is a double" << std::endl;
			convertDouble(input);
			break;
		case PSEUDO:
			std::cout << "Input is a pseudo literal" << std::endl;
			convertPseudo(input);
			break;
		case UNKNOWN:
			std::cout << "Input " << input << " is invalid" << std::endl;
			break;

		default:
			break;
	}
};
