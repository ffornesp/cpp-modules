/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:46:02 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/08 10:51:40 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>

class	Contact {
	
	public:
		Contact( void );
		~Contact( void );

		// Getters
		std::string	getName(void) const ;
		std::string	getLastName(void) const ;
		std::string	getNickname(void) const ;
		std::string	getNumber(void) const ;
		std::string	getSecret(void) const ;

		// Setters
		bool	setName(std::string str);
		bool	setLastName(std::string str);
		bool	setNickname(std::string str);
		bool	setNumber(std::string str);
		bool	setSecret(std::string str);

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif
