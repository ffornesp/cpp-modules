/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:19:02 by herz              #+#    #+#             */
/*   Updated: 2024/06/10 12:29:54 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.fwd.hpp"
#include "Form.hpp"

Form::Form( std::string name, unsigned int sGrade, unsigned int eGrade ) : _name(name), _sGrade(sGrade), _eGrade(eGrade) {
	this->_sign = false;
	try	{
		if ( this->_sGrade < 1 )
			throw Form::GradeTooHighException();
		if ( this->_eGrade < 1 )
			throw Form::GradeTooHighException();
		if ( this->  _sGrade > 150 )
			throw Form::GradeTooLowException();
		if ( this->_eGrade > 150 )
			throw Form::GradeTooLowException();
	}
	catch	( Form::GradeTooHighException& e ) {
		std::cerr << "Form grade is too high" << std::endl;
	}
	catch	( Form::GradeTooLowException& e ) {
		std::cerr << "Form grade is too low" << std::endl;
	}
}
Form::~Form( void ) {

}
Form::Form( const Form& form ) : _name(form._name), _sign(form._sign), _sGrade(form._sGrade), _eGrade(form._eGrade) {

}
Form& Form::operator=( const Form& form ) {
	if ( this != &form ) {
		this->_sign = form._sign;
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& os, const Form& f ) {
	os << "Form name:\t" << f.getName() << std::endl << "Form signed:\t";
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
	try {
		if ( !this->_sign && b.getGrade() <= getSGrade() ) {
			this->_sign = true;	
			signForm(b);
		}
		else if ( this->_sign )
			std::cerr << b.getName() << " couldn't sign " << this->getName() << " because it was already signed" << std::endl;
		else
			throw Form::GradeTooLowException();
	}
	catch	( Form::GradeTooLowException& e ) {
		signForm( b );
	}
}

void			Form::signForm( Bureaucrat b ) {
	if ( this->_sign )
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	else
		std::cerr << b.getName() << " couldn't sign " << this->getName() << " because grade was not high enough" << std::endl;
}
