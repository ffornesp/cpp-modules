/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:35:37 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/06 10:33:49 by ffornes-         ###   ########.fr       */
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
		void	searchContact(int id) const;
		void	printPhoneBook( void ) const;
	private:
		Contact	_contacts[8];
};

#endif
