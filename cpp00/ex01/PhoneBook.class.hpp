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

#ifndef ALPHA
# define ALPHA	0
#endif
#ifndef NUM
# define NUM	1
#endif

#include "Contact.class.hpp"

class PhoneBook {
	
	public:
		PhoneBook( void );
		~PhoneBook( void );
		void	addContact(Contact contact);
		void	searchContact(int id) const;
		void	printPhoneBook( void ) const;
		int		getContactAmount( void ) const;
		void	setContactAmount( void );
	private:
		Contact	_contacts[8];
		int		_nContacts;
};

#endif
