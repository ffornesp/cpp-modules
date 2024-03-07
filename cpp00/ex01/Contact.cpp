/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:59:21 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/07 11:01:32 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "utils.hpp"
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
	if (!emptyCheck(str))
		return false;
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)	{
		if (!std::isalpha((char)*it) && *it != ' ') {
			std::cerr << "Error: must only contain letters" << std::endl;
			return false;
		}
	}
	this->FirstName = str;
	return true;
}

bool	Contact::setLastName(std::string str) {
	if (!emptyCheck(str))
		return false;
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)	{
		if (!std::isalpha((char)*it)) {
			std::cerr << "Error: must only contain letters" << std::endl;
			return false;
		}
	}
	this->LastName = str;
	return true;
}

bool	Contact::setNickname(std::string str) {
	if (!emptyCheck(str))
		return false;
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)	{
		if (!std::isalpha((char)*it)) {
			std::cerr << "Error: must only contain letters" << std::endl;
			return false;
		}
	}
	this->Nickname = str;
	return true;
}

bool	Contact::setNumber(std::string str) {
	if (!emptyCheck(str))
		return false;
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it) {
		if (!std::isdigit((char)*it)) {
			std::cerr << "Error: must only contain numbers"  << std::endl;
			return false;
		}
	}
	this->PhoneNumber = str;
	return true;
}

bool	Contact::setSecret(std::string str) {
	if (!emptyCheck(str))
		return false;
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)	{
		if (!std::isalpha((char)*it) && *it != ' ') {
			std::cerr << "Error: must only contain letters" << std::endl;
			return false;
		}
	}
	this->DarkestSecret = str;
	return true;
}
