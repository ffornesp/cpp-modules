/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:38:03 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/08 10:49:27 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.class.hpp"
#include "utils.hpp"
#include "phonebookDefs.hpp"

PhoneBook::PhoneBook( void ) {
	return;
}

PhoneBook::~PhoneBook( void ) {
	return;
}

void	PhoneBook::addContact( Contact contact ) {
	this->_contacts[this->_nContacts] = contact;
	this->_nContacts++;
	if (this->_nContacts > 7)
		this->_nContacts = 0;
	return;
}

bool	PhoneBook::printContact( std::string str ) const {
	int		id;
	size_t	i;
	size_t	j;

	if (str.empty()) 
		return (errorMessage("you forgot to write an id.", false));
	i = 0;
	j = 0;
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)	{
		if (std::isspace((char)*it))
			i++;
		else if (std::isdigit((char)*it))
			j++;
		else
			return (errorMessage("should contain one digit only.", false));
	}
	if (i == str.length())
		return (errorMessage("you forgot to write an id.", false));
	else if (i > 0)
		return (errorMessage("should contain one digit only.", false));
	if (str.length() > 1)
		return (errorMessage("should contain one digit only.", false));
	id = std::atoi(str.c_str());
	if (id < 1 || id > 8)
		return (errorMessage("index out of range.", false));
	if (_contacts[--id].getName().empty())
		return (errorMessage("this contact is empty.", true));
	std::cout << std::endl;
	std::cout << YELLOW "Name:		" WHITE << _contacts[id].getName() << std::endl;
	std::cout << YELLOW "Last Name:	" WHITE << _contacts[id].getLastName() << std::endl;
	std::cout << YELLOW "Nickname:	" WHITE << _contacts[id].getNickname() << std::endl;
	std::cout << YELLOW "Phone number: 	" WHITE << _contacts[id].getNumber() << std::endl;
	std::cout << YELLOW "Darkest secret:	" WHITE << _contacts[id].getSecret() << std::endl;
	return true;
}

void	PhoneBook::printContactTable( int id ) const {
	std::string	aux;

	aux = std::to_string(id + 1);
	std::cout << std::setfill(' ') << std::setw(10) << aux << "|";

	aux = _contacts[id].getName();
	if (aux.length() > 10)
		aux = trimString(aux);
	std::cout << std::setfill(' ') << std::setw(10) << aux << "|";

	aux = _contacts[id].getLastName();
	if (aux.length() > 10)
		aux = trimString(aux);
	std::cout << std::setfill(' ') << std::setw(10) << aux << "|";

	aux = _contacts[id].getNickname();
	if (aux.length() > 10)
		aux = trimString(aux);
	std::cout << std::setfill(' ') << std::setw(10) << aux;
	if (id < 7)
		std::cout << std::endl;
	return;
}

//	Getters

int		PhoneBook::getContactAmount(void) const {
	return this->_nContacts;
}
