/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:40:22 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/06 10:42:53 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>

int	main() {
	
	Contact contact;

	if (contact.setName("Hol4i"))
		std::cout << contact.getName() << std::endl;
	if (contact.setLastName("i2wi"))
		std::cout << contact.getLastName() << std::endl;
	if (contact.setNickname("ki1wi"))
		std::cout << contact.getNickname() << std::endl;
	if (contact.setNumber("42a0"))
		std::cout << contact.getNumber() << std::endl;
	if (contact.setSecret("Da5rk"))
		std::cout << contact.getSecret() << std::endl;
	return (0);
}
