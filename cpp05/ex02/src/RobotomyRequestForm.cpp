/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:55:40 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/10 17:45:11 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm( void ) : _target( "default" ) {}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& old ) : AForm("RobotomyRequestForm", 72, 45) {
	*this = old;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& old ) {
	if ( this != &old ) {
		this->AForm::_sign = old.AForm::_sign;
		this->_target = old._target;
	}
	return (*this);
}

std::string	RobotomyRequestForm::getTarget( void ) const {
	return ( this->_target );
}

void	RobotomyRequestForm::action( void ) const {
	int	i;

	std::srand(std::time(NULL));
	i = std::rand();
	std::cout << "brrrrrrrrrrrrr *Drill noises*" << std::endl;
	sleep(2);
	std::cout << "brrr brrr brrr *Drill noises*" << std::endl;
	sleep(1);
	std::cout << "brrrrrrrrrrrrr *Drill noises*" << std::endl;
	sleep(2);
	if ( i % 2 )
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << "'s robotomy has failed..." << std::endl;
}
