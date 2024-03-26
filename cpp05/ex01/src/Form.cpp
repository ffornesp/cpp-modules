/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:19:02 by herz              #+#    #+#             */
/*   Updated: 2024/03/26 16:13:42 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( std::string name, unsigned int sGrade, unsigned int eGrade ) : _name(name), _sGrade(sGrade), _eGrade(eGrade) {
	this->_sign = false;
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

void			Form::beSigned( Bureaucrat b );
