/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:52:51 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/14 21:56:21 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::GradeTooLowException::GradeTooLowException( const std::string& msg ) : std::range_error( msg + "'s grade is too low\n" ) {}

Bureaucrat::GradeTooHighException::GradeTooHighException( const std::string& msg ) : std::range_error( msg + "'s grade is too high\n" ) {}

Bureaucrat::Bureaucrat ( void ) : _name( "default" ), _grade( 150 ) {}

Bureaucrat::Bureaucrat ( std::string name, unsigned int grade ) : _name(name) {
	setGrade( grade );
}

Bureaucrat::~Bureaucrat ( void ) {}

Bureaucrat::Bureaucrat ( const Bureaucrat& old ) : _name(old._name), _grade(old._grade) {}

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
	os << "Name: " << b.getName() << " | Grade: " << b.getGrade();
	return os;
}

void	Bureaucrat::setGrade( unsigned int grade ) {
	try	{
		if ( grade < 1 ) {
			this->_grade = 1;
			throw ( Bureaucrat::GradeTooHighException( "[" + this->getName() + "]" ) );
		}
		else if ( grade > 150 ) {
			this->_grade = 150;
			throw ( Bureaucrat::GradeTooLowException( "[" + this->getName() + "]" ) );
		}
		else
			this->_grade = grade;
	}
	catch	( Bureaucrat::GradeTooHighException& e ) {
		std::cerr << e.what();
	}
	catch	( Bureaucrat::GradeTooLowException& e ) {
		std::cerr << e.what();
	}
}

void	Bureaucrat::increment( void ) {
	setGrade( this->_grade - 1 );
}
void	Bureaucrat::decrement( void ) {
	setGrade( this->_grade + 1 );
}

void	Bureaucrat::signForm( AForm& f ) const {
	try {
		if ( !f.getSign() ) {
			f.beSigned( *this );
			std::cout << "[" + this->getName() + "] signed [" + f.getName() + "]" << std::endl;
		}
		else
			throw( AForm::AlreadySignedException( "[" + f.getName() + "]" ) );
	}
	catch ( Bureaucrat::GradeTooLowException& e ) {
		std::cerr << "[" + this->getName() + "] couldn't sign [" + f.getName() + "] because " << e.what();
	}
	catch ( AForm::AlreadySignedException& e ) {
		std::cerr << "[" + this->getName() + "] couldn't sign [" + f.getName() + "] because " << e.what();
	}
}

void	Bureaucrat::executeForm( AForm const & form ) const {
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch ( AForm::UnsignedFormException& e ) {
		std::cerr << e.what();
	}
	catch ( AForm::GradeTooLowException& e ) {
		std::cerr << e.what();
	}
	catch ( AForm::UnableToOpenFileException& e ) {
		std::cerr << e.what();
	}
}
