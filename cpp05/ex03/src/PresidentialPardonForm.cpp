/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:55:35 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/10 17:44:50 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : _target( "default" ) {}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& old ) : AForm("PresidentialPardonForm", 25, 5) {
	*this = old;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& old ) {
	if ( this != &old ) {
		this->AForm::_sign = old.AForm::_sign;
		this->_target = old._target;
	}
	return (*this);
}

std::string	PresidentialPardonForm::getTarget( void ) const {
	return ( this->_target );
}

void	PresidentialPardonForm::action( void ) const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
