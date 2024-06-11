/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:13:19 by herz              #+#    #+#             */
/*   Updated: 2024/06/11 13:13:22 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "Bureaucrat.fwd.hpp"
#include "Bureaucrat.hpp"

class	AForm {
	private:
	protected:
		const std::string	_name;
		bool				_sign;
		const unsigned int	_sGrade;
		const unsigned int	_eGrade;
	public:
		AForm( std::string name, unsigned int sGrade, unsigned int eGrade );
		~AForm( void );
		AForm( const AForm& );
		AForm& operator=( const AForm& );

		std::string		getName( void ) const;
		bool			getSign( void ) const;
		unsigned int	getSGrade( void ) const;
		unsigned int	getEGrade( void ) const;

		void			beSigned( Bureaucrat b );
		void			signForm( Bureaucrat b, bool flag );
		void			execute( Bureaucrat const & executor ) const ;

	class	GradeTooLowException : public std::exception {
		public:
			virtual const char*	what() const throw() {
				return ("Grade is too low");
			}
	};

	class	GradeTooHighException : public std::exception {
		public:
			virtual const char*	what() const throw() {
				return ("Grade is too high");
			}
	};

	class	UnsignedFormException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Form is unsigned");
			}
	};
};

std::ostream& operator<<( std::ostream& os, const AForm& f );
