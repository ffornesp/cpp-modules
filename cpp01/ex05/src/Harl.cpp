/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:52:28 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/12 10:07:30 by ffornes-         ###   ########.fr       */
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
	for (size_t i = 0; i < 4; i++)
	{
		if (_levels[i] == level) {
			(this->*_functionPtr[i])();
		}
	}
	
}

void	Harl::_debug( void ) {
	std::cout << "I love having extra bacon for my " \
	"7XL-double-cheese-triple-pickle-special-ketchup " \
	"burger. I really do!" << std::endl;
}

void	Harl::_info( void ) {
	std::cout << "I cannot believe adding extra bacon " \
	"costs more money. You didn’t put enough bacon in my " \
	"burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning( void ) {
	std::cout << "I think I deserve to have some extra " \
	"bacon for free. I’ve been coming for years whereas " \
	"you started working here since last month." << std::endl;
}

void	Harl::_error( void ) {
	std::cout << "This is unacceptable! I want to speak " \
	"to the manager now." << std::endl;
}