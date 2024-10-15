/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:19:02 by herz              #+#    #+#             */
/*   Updated: 2024/10/15 16:48:48 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.fwd.hpp"
#include "Form.hpp"

Form::GradeTooLowException::GradeTooLowException( const std::string& msg ) : std::range_error( "Can't create " + msg + "grade is too low\n" ) {}

Form::GradeTooHighException::GradeTooHighException( const std::string& msg ) : std::range_error( "Can't create " + msg + "grade is too high\n" ) {}

Form::AlreadySignedException::AlreadySignedException( const std::string& msg ) : std::logic_error( msg + " is already signed\n" ) {}

Form::Form( void ) : _name( "defaultForm" ), _sign( false ), _sGrade( 150 ), _eGrade( 150 ) {}

Form::Form( std::string name, unsigned int sGrade, unsigned int eGrade ) : _name(name), _sign(false), _sGrade(sGrade), _eGrade(eGrade) {
	if ( sGrade < 1 )
		throw Form::GradeTooHighException( "[" + this->getName() + "] because it's required sign " );
	else if ( sGrade > 150 )
		throw Form::GradeTooLowException( "[" + this->getName() + "] because it's required sign " );
	if ( eGrade < 1 )
		throw Form::GradeTooHighException( "[" + this->getName() + "] because it's required execute " );
	else if ( eGrade > 150 )
		throw Form::GradeTooLowException( "[" + this->getName() + "] because it's required execute " );
}

Form::~Form( void ) {}

Form::Form( const Form& form ) : _name(form._name), _sign(form._sign), _sGrade(form._sGrade), _eGrade(form._eGrade) {}

Form& Form::operator=( const Form& form ) {
	if ( this != &form ) {
		this->_sign = form._sign;
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& os, const Form& f ) {
	os << "Form name:\t\t\t" << f.getName() << std::endl << "Form signed:\t\t\t";
	if ( f.getSign() )
		os << "Yes" << std::endl;
	else
		os << "No" << std::endl;
	os << "Grade required to sign:\t\t" << f.getSGrade() << std::endl;
	os << "Grade required to execute:\t" << f.getEGrade() << std::endl;
	return os;
}

std::string		Form::getName( void ) const {
	return (this->_name);
}
bool			Form::getSign( void ) const {
	return (this->_sign);
}
unsigned int	Form::getSGrade( void ) const {
	return (this->_sGrade);
}
unsigned int	Form::getEGrade( void ) const {
	return (this->_eGrade);
}

void			Form::beSigned( Bureaucrat b ) {
	if ( b.getGrade() <= this->_sGrade )
		this->_sign = true;
	else
		throw Bureaucrat::GradeTooLowException( b.getName() );
}
