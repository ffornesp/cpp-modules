/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:59:21 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/07 13:16:05 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "utils.hpp"
#include "phonebookDefs.hpp"
#include <string>

Contact::Contact( void ) {
	return;
}

Contact::~Contact( void ) {
	return;
}

//	Getters

std::string Contact::getName(void) const {
	return this->FirstName;
}

std::string	Contact::getLastName(void) const {
	return this->LastName;
}

std::string	Contact::getNickname(void) const {
	return this->Nickname;
}

std::string	Contact::getNumber(void) const {
	return this->PhoneNumber;
}

std::string	Contact::getSecret(void) const {
	return this->DarkestSecret;
}

//	Setters

bool	Contact::setName(std::string str) {
	if (!emptyCheck(str, FIELD))
		return false;
	if (!fieldCheck(str, CHAR))
		return false;
	this->FirstName = str;
	return true;
}

bool	Contact::setLastName(std::string str) {
	if (!emptyCheck(str, FIELD))
		return false;
	if (!fieldCheck(str, CHAR))
		return false;
	this->LastName = str;
	return true;
}

bool	Contact::setNickname(std::string str) {
	if (!emptyCheck(str, FIELD))
		return false;
	if (!fieldCheck(str, CHAR))
		return false;
	this->Nickname = str;
	return true;
}

bool	Contact::setNumber(std::string str) {
	if (!emptyCheck(str, FIELD))
		return false;
	if (!fieldCheck(str, NUM))
		return false;
	this->PhoneNumber = str;
	return true;
}

bool	Contact::setSecret(std::string str) {
	if (!emptyCheck(str, FIELD))
		return false;
	if (!fieldCheck(str, CHAR))
		return false;
	this->DarkestSecret = str;
	return true;
}
