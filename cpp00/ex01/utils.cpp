/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:56:31 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/08 11:12:42 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookDefs.hpp"
#include <iostream>

std::string	trimString(std::string str) {
	str.insert(9, ".");
	str.erase(10);
	return (str);
}

bool	errorMessage(std::string str, bool out) {
	std::cerr << RED"Error: " << str << WHITE << std::endl;
	return out;
}

bool	emptyCheck(std::string str, bool flag) {
	if (str.empty()) {
		if (flag == FIELD)
			return (errorMessage("field can't be empty.", false));
		else if (flag == COMMAND)
			return (errorMessage("you forgot to write the command.", false));
	}
	size_t	i = 0;
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)	{
		if (!std::isspace((char)*it))
			break ;
		i++;
	}
	if (flag == FIELD && i == str.length())
		return (errorMessage("field can't be empty.", false));
	else if (flag == COMMAND && i == str.length())
		return (errorMessage("you forgot to write the command.", false));
	return true;
}

bool	fieldCheck(std::string str, bool flag) {
	if (flag == NUM) {
		for (std::string::iterator it=str.begin(); it!=str.end(); ++it)
			if (!std::isdigit((char)*it))
				return (errorMessage("must only contain numbers.", false));
	}
	else if (flag == CHAR)
		for (std::string::iterator it=str.begin(); it!=str.end(); ++it)
			if (!std::isalpha((char)*it) && *it != ' ')
				return (errorMessage("must only contain letters.", false));
	return true;
}
