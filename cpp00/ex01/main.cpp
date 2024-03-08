/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:40:22 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/08 11:12:58 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "PhoneBookDefs.hpp"
#include "Contact.class.hpp"
#include "utils.hpp"
#include <iostream>
#include <iomanip>

static std::string	input(std::string str, bool flag) {
	std::string	buff;

	std::cout << std::endl;
	if (flag)
		std::cout << WHITE"Introduce " << str;
	else if (!flag)
		std::cout << WHITE"Introduce the contacts " << str;
	if (!std::getline(std::cin, buff))
		exit(0);
	return (buff);
}

static bool	add( PhoneBook *phonebook ) {
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
	return true;
}

static bool	search( PhoneBook phonebook ) {
	std::string	str;

	std::cout << std::endl << "  INDEX   |   NAME   | LASTNAME | NICKNAME " << std::endl;
	
	for (size_t i = 0; i < 3; i++)
		std::cout << std::setfill(' ') << std::setw(11) << "|";
	std::cout << std::endl;
	for (size_t i = 0; i < 8; i++)
		phonebook.printContactTable(i);
	std::cout << std::endl;
	while (!phonebook.printContact(input("an ID of a contact : ", true)))
		;
	return true;
}

int	main(int argc, char *argv[]) {
	PhoneBook	phonebook;
	std::string	str;

	if (argc > 1) {
		errorMessage("usage: ./PhoneBook", false);
		return (0);
	}
	while (42) {
		str = input("a command { ADD, SEARCH, EXIT } : ", true);
		if (!str.compare("ADD\0"))
			add(&phonebook);
		else if (!str.compare("SEARCH\0"))
			search(phonebook);
		else if (!str.compare("EXIT\0"))
			break ;
		else if (emptyCheck(str, COMMAND))
			std::cout << RED "Error: invalid command." WHITE << std::endl;
	}
	(void)argv;
	return (0);
}
