/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:59:21 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/08 11:12:29 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "utils.hpp"
#include "PhoneBookDefs.hpp"
#include <string>

Contact::Contact( void ) {
	return;
}

Contact::~Contact( void ) {
	return;
}

//	Getters

std::string Contact::getName(void) const {
	return this->_firstName;
}

std::string	Contact::getLastName(void) const {
	return this->_lastName;
}

std::string	Contact::getNickname(void) const {
	return this->_nickname;
}

std::string	Contact::getNumber(void) const {
	return this->_phoneNumber;
}

std::string	Contact::getSecret(void) const {
	return this->_darkestSecret;
}

//	Setters

bool	Contact::setName(std::string str) {
	if (!emptyCheck(str, FIELD))
		return false;
	if (!fieldCheck(str, CHAR))
		return false;
	this->_firstName = str;
	return true;
}

bool	Contact::setLastName(std::string str) {
	if (!emptyCheck(str, FIELD))
		return false;
	if (!fieldCheck(str, CHAR))
		return false;
	this->_lastName = str;
	return true;
}

bool	Contact::setNickname(std::string str) {
	if (!emptyCheck(str, FIELD))
		return false;
	if (!fieldCheck(str, CHAR))
		return false;
	this->_nickname = str;
	return true;
}

bool	Contact::setNumber(std::string str) {
	if (!emptyCheck(str, FIELD))
		return false;
	if (!fieldCheck(str, NUM))
		return false;
	this->_phoneNumber = str;
	return true;
}

bool	Contact::setSecret(std::string str) {
	if (!emptyCheck(str, FIELD))
		return false;
	if (!fieldCheck(str, CHAR))
		return false;
	this->_darkestSecret = str;
	return true;
}
