/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:59:21 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/06 10:53:05 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <string>

Contact::Contact( void ) {
	std::cout << "Constructor called" << std::endl;
	return;
}

Contact::~Contact( void ) {
	std::cout << "Destructor called" << std::endl;
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
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)	{
		if (!isalpha((char)*it)) {
			std::cout << "Error: must only contain letters" << std::endl;
			return false;
		}
	}
	this->FirstName = str;
	return true;
}

bool	Contact::setLastName(std::string str) {
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)	{
		if (!isalpha((char)*it)) {
			std::cout << "Error: must only contain letters" << std::endl;
			return false;
		}
	}
	this->LastName = str;
	return true;
}

bool	Contact::setNickname(std::string str) {
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)	{
		if (!isalpha((char)*it)) {
			std::cout << "Error: must only contain letters" << std::endl;
			return false;
		}
	}
	this->Nickname = str;
	return true;
}

bool	Contact::setNumber(std::string str) {
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it) {
		if (!isdigit((char)*it)) {
			std::cout << "Error: must only contain numbers"  << std::endl;
			return false;
		}
	}
	this->PhoneNumber = str;
	return true;
}

bool	Contact::setSecret(std::string str) {
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it) {
		if (!isalpha((char)*it)) {
			std::cout << "Error: must only contain letters" << std::endl;
			return false;
		}
	}
	this->DarkestSecret = str;
	return true;
}
