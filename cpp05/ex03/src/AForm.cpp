/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:19:02 by herz              #+#    #+#             */
/*   Updated: 2024/10/14 22:08:11 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.fwd.hpp"
#include "AForm.hpp"

AForm::GradeTooLowException::GradeTooLowException( const std::string& msg ) : std::range_error( msg + " grade is too low\n" ) {}

AForm::GradeTooHighException::GradeTooHighException( const std::string& msg ) : std::range_error( msg + " grade is too high\n" ) {}

AForm::AlreadySignedException::AlreadySignedException( const std::string& msg ) : std::logic_error( msg + " is already signed\n" ) {}

AForm::UnsignedFormException::UnsignedFormException( const std::string& msg ) : std::logic_error( msg + " isn't signed yet\n" ) {}

AForm::UnableToOpenFileException::UnableToOpenFileException( const std::string& msg ) : std::logic_error( msg + " execution error. Unable to open the output file\n" ) {}

AForm::AForm( void ) : _name( "default" ), _sign( false ), _sGrade( 150 ), _eGrade( 150 ) {}

AForm::AForm( std::string name, unsigned int sGrade, unsigned int eGrade ) : _name(name), _sign( false ), _sGrade(sGrade), _eGrade(eGrade) {
	this->_sign = false;
	try	{
		if ( this->_sGrade < 1 || this->_eGrade < 1 )
			throw AForm::GradeTooHighException( this->getName() + " required " );
		else if ( this->  _sGrade > 150 || this->_eGrade > 150 )
			throw AForm::GradeTooLowException( this->getName() + " required " );
	}
	catch	( AForm::GradeTooHighException& e ) {
		std::cerr << e.what();
	}
	catch	( AForm::GradeTooLowException& e ) {
		std::cerr << e.what();
	}
}

AForm::~AForm( void ) {}

AForm::AForm( const AForm& form ) : _name(form._name), _sign(form._sign), _sGrade(form._sGrade), _eGrade(form._eGrade) {}

AForm& AForm::operator=( const AForm& form ) {
	if ( this != &form ) {
		this->_sign = form._sign;
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& os, const AForm& f ) {
	os << "Form name:\t" << f.getName() << std::endl << "Form signed:\t";
	if ( f.getSign() )
		os << "Yes" << std::endl;
	else
		os << "No" << std::endl;
	os << "Grade required to sign:\t\t" << f.getSGrade() << std::endl;
	os << "Grade required to execute:\t" << f.getEGrade() << std::endl;
	return os;
}

std::string		AForm::getName( void ) const {
	return (this->_name);
}
bool			AForm::getSign( void ) const {
	return (this->_sign);
}
unsigned int	AForm::getSGrade( void ) const {
	return (this->_sGrade);
}
unsigned int	AForm::getEGrade( void ) const {
	return (this->_eGrade);
}

void			AForm::beSigned( Bureaucrat b ) {
	try {
		if ( b.getGrade() <= this->_sGrade )
			this->_sign = true;
		else
			throw Bureaucrat::GradeTooLowException( b.getName() );
	}
	catch ( Bureaucrat::GradeTooLowException& e ) {
		std::cerr << b.getName() + "couldn't sign [" + this->getName() + "] because " + e.what();
	}
}

void			AForm::execute( Bureaucrat const & executor ) const {
	if ( this->_sign ) {
		if ( this->_eGrade >= executor.getGrade() )
			this->action();
		else
			throw AForm::GradeTooLowException( executor.getName() + " can't sign because it" );
	}
	else
		throw AForm::UnsignedFormException( this->getName() + " can't be executed because it " );
}

void			AForm::action( void ) const {
	std::cout << "Action function called in AForm" << std::endl;
}
