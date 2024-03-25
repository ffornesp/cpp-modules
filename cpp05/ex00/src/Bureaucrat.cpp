/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:52:51 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/25 17:24:40 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat ( std::string name, unsigned int grade ) : _name(name) {
	try {
		setGrade( grade );
	}
	catch	(unsigned int n) {
		if ( n < 1 )
			std::cerr << "Grade too low" << std::endl;
		else if ( n > 150 )
			std::cerr << "Grade too high" << std::endl;
		setGrade( 1 );
	}
}
Bureaucrat::~Bureaucrat ( void ) {
	
}
Bureaucrat::Bureaucrat ( const Bureaucrat& old ) : _name(old._name), _grade(old._grade) {

}
Bureaucrat& Bureaucrat::operator=( const Bureaucrat& old ) {
	if ( this != &old )
		this->_grade = old._grade;
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

bool	Bureaucrat::setGrade( unsigned int grade ) {
	if ( grade < 1 )
		throw grade;
	else if ( grade > 150 )
		throw grade;
	else {
		this->_grade = grade;
		return true;
	}
	return false;
}

bool	Bureaucrat::increment( void ) {
	try {
		setGrade( this->_grade + 1 );
	}
	catch	(unsigned int n) {
		if ( n > 150 )
			std::cerr << "Grade too high" << std::endl;
	}
	return true;
}
bool	Bureaucrat::decrement( void ) {
	try {
		if ( this->_grade > 0 )
			setGrade( this->_grade - 1 );
		else
			setGrade( 0 );
	}
	catch	(unsigned int n) {
		if ( n < 1 )
			std::cerr << "Grade too low" << std::endl;
	}
	return true;
}
