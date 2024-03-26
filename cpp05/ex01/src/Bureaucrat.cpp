/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:52:51 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/26 14:10:26 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat ( std::string name, unsigned int grade ) : _name(name) {
	try {
		setGrade( grade );
	}
	catch	(Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Grade can't be lower than 150\n";
	}
	catch	(Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Grade can't be higher than 1\n";
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

void	Bureaucrat::setGrade( unsigned int grade ) {
	if ( grade < 1 ) {
		this->_grade = 1;
		throw (GradeTooHighException());
	}
	else if ( grade > 150 ) {
		this->_grade = 150;
		throw (GradeTooLowException());
	}
	else
		this->_grade = grade;
}

void	Bureaucrat::increment( void ) {
	try {
		setGrade( this->_grade - 1 );
	}
	catch	(Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Grade can't be higher than 1\n";
	}
}
void	Bureaucrat::decrement( void ) {
	try {
		setGrade( this->_grade + 1 );
	}
	catch	(Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Grade can't be lower than 150\n";
	}
}
