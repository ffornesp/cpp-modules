/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:19:02 by herz              #+#    #+#             */
/*   Updated: 2024/06/05 16:03:25 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.fwd.hpp"
#include "Form.hpp"

Form::Form( std::string name, unsigned int sGrade, unsigned int eGrade ) : _name(name), _sGrade(sGrade), _eGrade(eGrade) {
	this->_sign = false;
	if ( this->_sGrade < 1 || this->_eGrade < 1 )
		throw Form::GradeTooHighException();
	else if ( this->  _sGrade > 150 || this->_eGrade > 150 )
		throw Form::GradeTooLowException();
}
Form::~Form( void ) {

}
Form::Form( const Form& form ) : _name(form._name), _sign(form._sign), _sGrade(form._sGrade), _eGrade(form._eGrade) {

}
Form& Form::operator=( const Form& form ) {
	if (this != &form) {
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
	if ( getSign() ) {
		std::cout << "Form is already signed" << std::endl;
		return ;
	}
	if ( b.getGrade() <= getSGrade() ) {
		this->_sign = true;	
	}
	else
		throw Form::GradeTooLowException();
}
