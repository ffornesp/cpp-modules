/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:52:51 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/25 14:12:30 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat ( std::string name, unsigned int grade ) : _name(name) {
	this->_grade = grade;
}
Bureaucrat::~Bureaucrat ( void ) {
	
}
Bureaucrat::Bureaucrat ( const Bureaucrat& old ) {
	*this = old;
}
Bureaucrat& Bureaucrat::operator=( const Bureaucrat& old ) {
	if ( this != &old ) {
		(std::string)this->_name = old._name;
		this->_grade = old._grade;
	}
	return (*this);
}

std::string		Bureaucrat::getName( void ) const {
	return this->_name;
}
unsigned int	Bureaucrat::getGrade( void ) const {
	return this->_grade;
}

std::ostream&	operator<<( std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
