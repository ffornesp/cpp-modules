/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:38:03 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/06 14:23:36 by ffornes-         ###   ########.fr       */
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
	return;
}

void	PhoneBook::searchContact( int id ) const {
	if (id >= 0)
		return;
	return;
}

void	PhoneBook::printPhoneBook( void ) const {
	
	return;
}

//	Getters

int		PhoneBook::getContactAmount(void) const {
	return this->_nContacts;
}

//	Setters

void	PhoneBook::setContactAmount(void) {
	this->_nContacts++;
	if (this->_nContacts > 7)
		this->_nContacts = 0;
}
