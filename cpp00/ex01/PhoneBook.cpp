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

PhoneBook::PhoneBook( void ){
	
	std::cout << "Constructor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook( void ){

	std::cout << "Destructor called" << std::endl;
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
	int	id;

	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)	{
		if (!std::isdigit((char)*it))
			return (false);
	}
//	id = std::atoi(str);
//	TODO: Convert all isdigit and stuff into std::isdigit
	return (true);
}

void	PhoneBook::printContactTable( int id ) const {
	int			i;
	std::string	aux;

	i = 0;
	aux = std::to_string(id + 1);
	while (aux.length() + i++ < 10)
		std::cout << " ";
	std::cout << aux << "|";

	i = 0;
	aux = _contacts[id].getName();
	while (aux.length() + i++ < 10)
		std::cout << " ";
	std::cout << aux << "|";

	i = 0;
	aux = _contacts[id].getLastName();
	while (aux.length() + i++ < 10)
		std::cout << " ";
	std::cout << aux << "|";

	i = 0;
	aux = _contacts[id].getNickname();
	while (aux.length() + i++ < 10)
		std::cout << " ";
	std::cout << aux << std::endl;
	return;
}

//	Getters

int		PhoneBook::getContactAmount(void) const {
	return this->_nContacts;
}
