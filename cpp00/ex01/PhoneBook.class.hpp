/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:35:37 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/07 13:16:08 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class PhoneBook {
	
	public:
		PhoneBook( void );
		~PhoneBook( void );
		void	addContact(Contact contact);
		bool	getContact( void ) const;
		bool	printContact(std::string str) const;
		void	printContactTable(int id) const;
		int		getContactAmount( void ) const;
		void	setContactAmount( void );
	private:
		Contact	_contacts[8];
		int		_nContacts;
};

#endif
