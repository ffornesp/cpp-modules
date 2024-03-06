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

void	PhoneBook::searchContact( int id ) const {
	int			i;
	std::string	aux;

	i = 0;
	aux = std::to_string(id);
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

void	PhoneBook::printPhoneBook( void ) const {
	
	return;
}

//	Getters

int		PhoneBook::getContactAmount(void) const {
	return this->_nContacts;
}
