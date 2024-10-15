/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:19:02 by herz              #+#    #+#             */
/*   Updated: 2024/10/15 17:37:19 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.fwd.hpp"
#include "AForm.hpp"

AForm::GradeTooLowException::GradeTooLowException( const std::string& msg ) : std::range_error( msg + " grade is too low\n" ) {}

AForm::GradeTooHighException::GradeTooHighException( const std::string& msg ) : std::range_error( msg + " grade is too high\n" ) {}

AForm::AlreadySignedException::AlreadySignedException( const std::string& msg ) : std::logic_error( msg + " is already signed\n" ) {}

AForm::UnsignedFormException::UnsignedFormException( const std::string& msg ) : std::logic_error( msg + " not signed yet\n" ) {}

AForm::UnableToOpenFileException::UnableToOpenFileException( const std::string& msg ) : std::logic_error( "[" + msg + "] execution error. Unable to open the output file\n" ) {}

AForm::AForm( void ) : _name( "defaultForm" ), _sign( false ), _sGrade( 150 ), _eGrade( 150 ) {}

AForm::AForm( std::string name, unsigned int sGrade, unsigned int eGrade ) : _name(name), _sign( false ), _sGrade( sGrade ), _eGrade( eGrade ) {
	if ( sGrade < 1 )
		throw AForm::GradeTooHighException( "[" + this->getName() + "] because it's required sign " );
	else if ( sGrade > 150 )
		throw AForm::GradeTooLowException( "[" + this->getName() + "] because it's required sign " );
	if ( eGrade < 1 )
		throw AForm::GradeTooHighException( "[" + this->getName() + "] because it's required execute " );
	else if ( eGrade > 150 )
		throw AForm::GradeTooLowException( "[" + this->getName() + "] because it's required execute " );
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
		if ( b.getGrade() <= this->_sGrade ) {
			this->_sign = true;
			std::cout << "[" + b.getName() + "] signed " + this->getName() << std::endl;
		}
		else
			throw Bureaucrat::GradeTooLowException( b.getName() );
	}
	catch ( Bureaucrat::GradeTooLowException& e ) {
		std::cerr << RED << "[" + b.getName() + "] couldn't sign [" + this->getName() + "] because " + e.what() << RESET;
	}
}

void			AForm::execute( Bureaucrat const & executor ) const {
	if ( this->_sign ) {
		if ( this->_eGrade >= executor.getGrade() ) {
			std::cout << "[" + executor.getName() + "] executed " + this->getName() << std::endl;
			this->action();
		}
		else
			throw AForm::GradeTooLowException( "[" + executor.getName() + "] can't execute the form because it's" );
	}
	else
		throw AForm::UnsignedFormException( "[" + this->getName() + "] can't be executed because it's" );
}

void			AForm::action( void ) const {
	std::cout << "Action function called in AForm" << std::endl;
}
