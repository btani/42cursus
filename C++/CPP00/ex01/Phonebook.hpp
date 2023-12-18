/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:44:50 by btani             #+#    #+#             */
/*   Updated: 2023/11/28 14:44:52 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream> //std:cout, std::cin, std::endl, std::string
# include <string>
# include <iomanip> // std::setw

class PhoneBook
{
	private:
		Contact _contacts[8];
		int		_max_value;
		static int _add;
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void addCont(void);
		void searchCont(void);
		Contact *getContact() ;
};

#endif
