/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:20:40 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/11 17:51:01 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"
#include <string>
#include <iostream>

static int	message(std::string str, int errorId) {
	std::cerr << str << std::endl;
	return (errorId);
}

int	main(int argc, char *argv[]) {
	Harl		harl;
	std::string	str;

	if (argc != 2)
		return (message("Usage: ./harlFilter string_level", 1));
	str = argv[1];
	harl.complain(str);
	return (0);
}