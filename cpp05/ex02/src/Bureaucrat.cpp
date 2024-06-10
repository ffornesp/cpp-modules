/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:52:51 by ffornes-          #+#    #+#             */
/*   Updated: 2024/06/10 11:13:37 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat ( std::string name, unsigned int grade ) : _name(name) {
	setGrade( grade );
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
	try	{
		if ( grade < 1 ) {
			this->_grade = 1;
			throw (Bureaucrat::GradeTooHighException());
		}
		else if ( grade > 150 ) {
			this->_grade = 150;
			throw (Bureaucrat::GradeTooLowException());
		}
		else
			this->_grade = grade;
	}
	catch	(Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Bureaucrat grade is too high, defaulted to 1" << std::endl;
	}
	catch	(Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Bureaucrat grade is too low, defaulted to 150" << std::endl;
	}
}

void	Bureaucrat::increment( void ) {
	setGrade( this->_grade - 1 );
}
void	Bureaucrat::decrement( void ) {
	setGrade( this->_grade + 1 );
}
