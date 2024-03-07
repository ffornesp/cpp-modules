/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:56:31 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/07 10:59:38 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

bool	emptyCheck(std::string str) {
	if (str.empty()) {
		std::cerr << "Error: Field can't be empty" << std::endl;
		return false;
	}
	size_t	i = 0;
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)	{
		if (!std::isspace((char)*it))
			break ;
		i++;
	}
	if (i == str.length()) {
		std::cerr << "Error: field can't be empty." << std::endl;
		return false;
	}
	return true;
}