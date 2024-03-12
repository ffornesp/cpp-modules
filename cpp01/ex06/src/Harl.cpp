/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:52:28 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/12 10:08:26 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl( ) {
	_levels[0] = "DEBUG";
	_levels[1] = "INFO";
	_levels[2] = "WARNING";
	_levels[3] = "ERROR";
	_functionPtr[0] = &Harl::_debug;
	_functionPtr[1] = &Harl::_info;
	_functionPtr[2] = &Harl::_warning;
	_functionPtr[3] = &Harl::_error;
}

Harl::~Harl( ) {

}

void	Harl::complain(std::string level) {
	size_t	iterator;

	iterator = 0;
	while (iterator < 4) {
		if (_levels[iterator] == level)
			break ;
		iterator++;
	}
	switch (iterator) {
		default :
			std::cout << "[ Probably complaining about insignificant " \
			"problems ]" << std::endl;
			break ;
		case DEBUG :
			this->_debug();
		case INFO :
			this->_info();
		case WARNING :
			this->_warning();
		case ERROR :
			this->_error();
	}
}

void	Harl::_debug( void ) {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my " \
	"7XL-double-cheese-triple-pickle-special-ketchup " \
	"burger. I really do!" << std::endl;
}

void	Harl::_info( void ) {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon " \
	"costs more money. You didn’t put enough bacon in my " \
	"burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning( void ) {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra " \
	"bacon for free. I’ve been coming for years whereas " \
	"you started working here since last month." << std::endl;
}

void	Harl::_error( void ) {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak " \
	"to the manager now." << std::endl;
}