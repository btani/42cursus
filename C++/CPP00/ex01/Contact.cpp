/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:43:54 by btani             #+#    #+#             */
/*   Updated: 2023/12/12 17:36:16 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Phonebook.hpp"
#include "Contact.hpp"
#include <cstdlib>

Contact::Contact(void) { };
Contact::~Contact(void) { };

std::string Contact::getFirstName() const
{
	return (_firstName);
};

std::string Contact::getLastName() const
{
	return (_lastName);
};

std::string Contact::getNickName() const
{
	return (_nickName);
};

std::string Contact::getPhoneNumber() const
{
	return (_phoneNumber);
};

std::string Contact::getDarkestSecret() const
{
	return (_darkestSecret);
};

void Contact::setFirstName(std::string firstName)
{
	_firstName = firstName;	
};

void Contact::setLastName(std::string lastName)
{
	_lastName = lastName;	
};

void Contact::setNickName(std::string nickName)
{
	_nickName = nickName;	
};

void Contact::setPhoneNumber(std::string phoneNumber)
{
	_phoneNumber = phoneNumber;	
};

void Contact::setDarkestSecret(std::string darkestSecret)
{
	_darkestSecret = darkestSecret;	
};

void Contact::setValue(Contact contact)
{
	std::string risposta;

	std::cout << std::endl;
	std::cout << "Insert your FirstName: " << std::endl;
	std::getline(std::cin, risposta);
	if (std::cin.eof())
		exit(1);
	if (!risposta.compare("") || !Contact::checkIfLetter(risposta))
	{
		while (!risposta.compare("") || !Contact::checkIfLetter(risposta))
		{
        	std::cout << "Error : Empty field not allowed piece of shit!" << std::endl;
			std::cout << std::endl;
			std::cout << "Insert your FirstName: " << std::endl;
			std::getline(std::cin, risposta);
			if (std::cin.eof())
				exit(1);
			if (!Contact::checkIfLetter(risposta))
				risposta.clear();
			if (risposta.compare("") && Contact::checkIfLetter(risposta))
				break ;
		}
	}
	setFirstName(risposta);
	std::cout << std::endl;
	risposta.clear();

	std::cout << "Insert your LastName: " << std::endl;
	std::getline(std::cin, risposta);
	if (std::cin.eof())
		exit(1);
	if (!risposta.compare("") || !Contact::checkIfLetter(risposta))
	{
		while (!risposta.compare("") || !Contact::checkIfLetter(risposta))
		{
        	std::cout << "Error : Empty field not allowed piece of shit!" << std::endl;
			std::cout << std::endl;
			std::cout << "Insert your LastName: " << std::endl;
			std::getline(std::cin, risposta);
			if (std::cin.eof())
				exit(1);
			if (!Contact::checkIfLetter(risposta))
				risposta.clear();
			if (risposta.compare("") && Contact::checkIfLetter(risposta))
				break ;
		}
	}
	setLastName(risposta);
	std::cout << std::endl;
	risposta.clear();
	
	std::cout << "Insert your NickName: " << std::endl;
	std::getline(std::cin, risposta);
	if (std::cin.eof())
		exit(1);
	if (!risposta.compare(""))
	{
		while (!risposta.compare(""))
		{
        	std::cout << "Error : Empty field not allowed piece of shit!" << std::endl;
			std::cout << std::endl;
			std::cout << "Insert your NickName: " << std::endl;
			std::getline(std::cin, risposta);
			if (std::cin.eof())
				exit(1);
			if (risposta.compare(""))
				break ;
		}
	}
    else if (!Contact::checkIfLetter(risposta))
    	std::cout << "Error : Invalid input" << std::endl;
	setNickName(risposta);
	std::cout << std::endl;
	risposta.clear();

	std::cout << "Insert your PhoneNumber: " << std::endl;
	std::getline(std::cin, risposta);
	if (std::cin.eof())
		exit(1);
	if (!risposta.compare("") || !Contact::checkIfDigit(risposta))
	{
		while (!risposta.compare("") || !Contact::checkIfDigit(risposta) || !Contact::checkNumbers(risposta))
		{
        	std::cout << "Error : Empty field/letters or number different from 10 digits not allowed piece of shit!" << std::endl;
			std::cout << std::endl;
			std::cout << "Insert your PhoneNumber: " << std::endl;
			std::getline(std::cin, risposta);
			if (std::cin.eof())
				exit(1);
			if (!Contact::checkIfDigit(risposta) )
				risposta.clear();
			else if (risposta.compare("") && Contact::checkIfDigit(risposta) && Contact::checkNumbers(risposta))
				break ;
		}
	}
	setPhoneNumber(risposta);
	std::cout << std::endl;
	risposta.clear();

	std::cout << "Insert your DarkestSecret: " << std::endl;
	std::getline(std::cin, risposta);
	if (std::cin.eof())
		exit(1);
	if (!risposta.compare(""))
	{
		while (!risposta.compare(""))
		{
        	std::cout << "Error : Empty field not allowed piece of shit!" << std::endl;
			std::cout << std::endl;
			std::cout << "Insert your DarkestSecret: " << std::endl;
			std::getline(std::cin, risposta);
			if (std::cin.eof())
				exit(1);
			if (risposta.compare(""))
				break ;
		}
	}
	setDarkestSecret(risposta);
	std::cout << std::endl;
	risposta.clear();
};

void  Contact::displayList(Contact *contact, int _max_value) const
{
	for (int i = 0; i < _max_value; i++)
	{
		std::string value;

		{
			std::cout << std::setw(10) << i + 1 << "|";
		}
		if (contact[i].getFirstName().length() > 9)
		{
			value = contact[i].getFirstName();
			std::cout << value.substr(0, 9) << ".|";
		}
		else
			std::cout << std::setw(10) << contact[i].getFirstName() << "|";

		if (contact[i].getLastName().length() > 9)
		{
			value = contact[i].getLastName();
			std::cout << value.substr(0, 9) << ".|";
		}
		else
			std::cout <<  std::setw(10) <<  contact[i].getLastName() << "|";

		if (contact[i].getNickName().length() > 9)
		{
			value = contact[i].getNickName();
			std::cout << value.substr(0, 9) << ".|";
		}
		else
			std::cout <<  std::setw(10) << contact[i].getNickName() << "|";
		std::cout << std::endl;
	}
};

void	Contact::displayCont() const
{
	
	std::cout << "FirstName: " << this->getFirstName() << std::endl;
	std::cout << "LastName: " << this->getLastName() << std::endl;
	std::cout << "NickName: " << this->getNickName() << std::endl;
	std::cout << "PhoneNumber: " << this->getPhoneNumber() << std::endl;
	std::cout << "DarkestSecret: " << this->getDarkestSecret() << std::endl;
};

bool	Contact::checkIfDigit (const std::string index)
{
    if (index.empty())
        return ( false );
    for (std::size_t i = 0; i < index.length(); i++)
        if (!std::isdigit(static_cast<unsigned char>(index[i])))
            return ( false );
    return ( true );
};

bool    Contact::checkIfLetter (const std::string index)
{
    if (index.empty())
        return ( false );
    for (std::size_t i = 0; i < index.length(); i++)
        if (std::isdigit(static_cast<unsigned char>(index[i])))
            return ( false );
    return ( true );
};

bool	Contact::checkNumbers (const std::string &index)
{
    for (std::size_t i = 0; i < index.length(); i++)
		if (index.length() != 10)
			return ( false );
	return ( true );	
};
