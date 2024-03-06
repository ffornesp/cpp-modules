/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:40:22 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/06 16:27:36 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>

static std::string	input(std::string str, bool flag) {
	std::string	buff;

	if (flag)
		std::cout << "Introduce " << str;
	else if (!flag)
		std::cout << "Introduce the contacts " << str;
	if (!std::getline(std::cin, buff))
		exit(0);
	return (buff);
}

static void	add( PhoneBook *phonebook ) {
	Contact contact;

	while (!contact.setName(input("Name: ", false)))
		;
	while (!contact.setLastName(input("Last Name: ", false)))
		;
	while (!contact.setNickname(input("Nickname: ", false)))
		;
	while (!contact.setNumber(input("Phone Number: ", false)))
		;
	while (!contact.setSecret(input("Darkest Secret: ", false)))
		;
	phonebook->addContact(contact);
}

static void	search( PhoneBook phonebook ) {
	int			i;
	std::string	str;

	i = 0;
	std::cout << "  INDEX   |   NAME   | LASTNAME | NICKNAME " << std::endl;
	std::cout << "          |          |          |          " << std::endl;
	while (i < 8)
		phonebook.printContactTable(i++);
	while (!phonebook.printContact(input("an ID of a contact : ", true)))
		;
}

int	main() {
	PhoneBook	phonebook;
	std::string	str;

	while (42) {
		str = input("a command { ADD, SEARCH, EXIT } : ", true);
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
