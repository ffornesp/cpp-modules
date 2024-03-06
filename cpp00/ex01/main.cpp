/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:40:22 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/06 14:23:32 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>

static std::string	input(std::string str) {
	char	buff[1025];

	std::cout << str;
	if (!(std::cin >> buff))
		exit(0);
	return (std::string(buff));
}

static void	add( PhoneBook *phonebook ) {
	Contact contact;

	while (!contact.setName(input("Introduce the contacts Name: ")))
		;
	while (!contact.setLastName(input("Introduce the contacts Last Name: ")))
		;
	while (!contact.setNickname(input("Introduce the contacts Nickname: ")))
		;
	while (!contact.setNumber(input("Introduce the contacts Phone Number: ")))
		;
	while (!contact.setSecret(input("Introduce the contacts Darkest Secret: ")))
		;
	phonebook->addContact(contact);
	phonebook->setContactAmount();
}

static void	search( PhoneBook phonebook ) {
	std::cout << "Command selected: SEARCH" << std::endl;
	phonebook.searchContact(0);
}

int	main() {
	char		buff[1025];
	PhoneBook	phonebook;

	while (42) {
		std::cout << "Please introduce a command { ADD, SEARCH, EXIT } : ";
		if (!(std::cin >> buff))
			return (0);
		if (!strcmp(buff, "ADD\0"))
			add(&phonebook);
		else if (!strcmp(buff, "SEARCH\0")) {
			search(phonebook);
		}
		else if (!strcmp(buff, "EXIT\0")) {
			std::cout << "Command selected: EXIT" << std::endl;
			break ;
		}
		else
			std::cout << "Error: \"" << buff << "\" is an invalid command." << std::endl;
	}
	return (0);
}
