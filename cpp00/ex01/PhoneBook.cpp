/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:38:03 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/06 14:25:31 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.class.hpp"

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
	int			id;

	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)	{
		if (!std::isdigit((char)*it))
			return false;
	}
	id = std::atoi(str.c_str());
	if (id < 1 || id > 8) {
		std::cerr << "Error: Index out of range" << std::endl;
		return false;
	}
	id--;
	if (_contacts[id].getName().empty()) {
		std::cerr << "Error: this contact is empty." << std::endl;
		return (true);
	}
	std::cout << "Name : " << _contacts[id].getName() << std::endl;
	std::cout << "Last Name : " << _contacts[id].getLastName() << std::endl;
	std::cout << "Nickname : " << _contacts[id].getNickname() << std::endl;
	std::cout << "Phone number : " << _contacts[id].getNumber() << std::endl;
	std::cout << "Darkest secret : " << _contacts[id].getSecret() << std::endl;
	return true;
}

void	PhoneBook::printContactTable( int id ) const {
	int			i;
	std::string	aux;

	i = 0;
	aux = std::to_string(id + 1);
	while (aux.length() + i++ < 9)
		std::cout << " ";
	std::cout << aux << " |";

	i = 0;
	aux = _contacts[id].getName();
	if (aux.length() > 10) {
		aux.insert(9, ".");
		aux.erase(10);
	}
	else
		while (aux.length() + i++ < 10)
			std::cout << " ";
	std::cout << aux << "|";

	i = 0;
	aux = _contacts[id].getLastName();
	if (aux.length() > 10) {
		aux.insert(9, ".");
		aux.erase(10);
	}
	else
		while (aux.length() + i++ < 10)
			std::cout << " ";
	std::cout << aux << "|";

	i = 0;
	aux = _contacts[id].getNickname();
	if (aux.length() > 10) {
		aux.insert(9, ".");
		aux.erase(10);
	}
	else
		while (aux.length() + i++ < 10)
			std::cout << " ";
	std::cout << aux << std::endl;
	return;
}

//	Getters

int		PhoneBook::getContactAmount(void) const {
	return this->_nContacts;
}
