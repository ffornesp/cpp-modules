/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:46:02 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/06 10:44:48 by ffornes-         ###   ########.fr       */
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
		std::string	FirstName;
		std::string	LastName;
		std::string	Nickname;
		std::string	PhoneNumber;
		std::string	DarkestSecret;
};

#endif
