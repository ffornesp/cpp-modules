/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:40:22 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/06 16:09:56 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>

static std::string	input(std::string str, bool flag) {
	char	buff[1025];

	if (flag)
		std::cout << "Introduce the contacts " << str;
	else
		std::cout << "Introduce a command " << str;
	if (!(std::cin >> buff))
		exit(0);
	return (std::string(buff));
}

static void	add( PhoneBook *phonebook ) {
	Contact contact;

	while (!contact.setName(input("Name: ", true)))
		;
	while (!contact.setLastName(input("Last Name: ", true)))
		;
	while (!contact.setNickname(input("Nickname: ", true)))
		;
	while (!contact.setNumber(input("Phone Number: ", true)))
		;
	while (!contact.setSecret(input("Darkest Secret: ", true)))
		;
	phonebook->addContact(contact);
}

static void	search( PhoneBook phonebook ) {
	std::cout << "Command selected: SEARCH" << std::endl;
	phonebook.searchContact(0);
}

int	main() {
	PhoneBook	phonebook;
	std::string	str;

	while (42) {
		str = input("{ ADD, SEARCH, EXIT } : ", false);
		if (!str.compare("ADD\0"))
			add(&phonebook);
		else if (!str.compare("SEARCH\0"))
			search(phonebook);
		else if (!str.compare("EXIT\0"))
			break ;
		else
			std::cout << "Error: \"" << str << "\" is an invalid command." << std::endl;
	}
	return (0);
}
