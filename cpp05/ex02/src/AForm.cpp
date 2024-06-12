/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:19:02 by herz              #+#    #+#             */
/*   Updated: 2024/06/12 14:36:48 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.fwd.hpp"
#include "AForm.hpp"

AForm::AForm( std::string name, unsigned int sGrade, unsigned int eGrade ) : _name(name), _sGrade(sGrade), _eGrade(eGrade) {
	this->_sign = false;
	try	{
		if ( this->_sGrade < 1 || this->_eGrade < 1 )
			throw AForm::GradeTooHighException();
		else if ( this->  _sGrade > 150 || this->_eGrade > 150 )
			throw AForm::GradeTooLowException();
	}
	catch	( AForm::GradeTooHighException& e ) {
		std::cerr << "Form grade is too high" << std::endl;
	}
	catch	( AForm::GradeTooLowException& e ) {
		std::cerr << "Form grade is too low" << std::endl;
	}
}
AForm::~AForm( void ) {

}
AForm::AForm( const AForm& form ) : _name(form._name), _sign(form._sign), _sGrade(form._sGrade), _eGrade(form._eGrade) {

}
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
	if ( b.getGrade() <= this->_sGrade )
		this->_sign = true;
	else
		throw AForm::GradeTooLowException();
}

void			AForm::execute( Bureaucrat const & executor ) const {
	if ( this->_sign ) {
		if ( this->_eGrade >= executor.getGrade() )
			this->action();
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::UnsignedFormException();
}

void			AForm::action( void ) const {
	std::cout << "Action function called in AForm" << std::endl;
}
