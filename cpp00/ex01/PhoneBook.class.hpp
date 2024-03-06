/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:35:37 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/06 14:23:34 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#ifndef		COMMAND
# define	COMMAND	0
#endif
#ifndef 	CONTACT
# define	CONTACT	1
#endif
#ifndef 	ID
# define	ID		2
#endif

#include "Contact.class.hpp"

class PhoneBook {
	
	public:
		PhoneBook( void );
		~PhoneBook( void );
		void	addContact(Contact contact);
		bool	printContact(std::string str) const;
		void	printContactTable(int id) const;
		bool	getContact( void ) const;
		int		getContactAmount( void ) const;
		void	setContactAmount( void );
	private:
		Contact	_contacts[8];
		int		_nContacts;
};

#endif
