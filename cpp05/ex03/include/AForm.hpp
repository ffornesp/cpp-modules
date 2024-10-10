/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:13:19 by herz              #+#    #+#             */
/*   Updated: 2024/10/10 17:39:34 by ffornes-         ###   ########.fr       */
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
		AForm( void );
		AForm( std::string name, unsigned int sGrade, unsigned int eGrade );
		virtual ~AForm( void );
		AForm( const AForm& );
		AForm& operator=( const AForm& );

		std::string		getName( void ) const;
		bool			getSign( void ) const;
		unsigned int	getSGrade( void ) const;
		unsigned int	getEGrade( void ) const;

		void			beSigned( Bureaucrat b );
		void			execute( Bureaucrat const & executor ) const ;
		virtual void	action( void ) const ;

	class	GradeTooLowException : public std::range_error {
		public:
			GradeTooLowException( const std::string &msg );
	};

	class	GradeTooHighException : public std::range_error {
		public:
			GradeTooHighException( const std::string &msg );
	};

	class	AlreadySignedException : public std::logic_error {
		public:
			AlreadySignedException( const std::string &msg );
	};

	class	UnsignedFormException : public std::logic_error {
		public:
			UnsignedFormException( const std::string &msg );
	};
	
	class	UnableToOpenFileException : public std::logic_error {
		public:
			UnableToOpenFileException( const std::string &msg );
	};
};

std::ostream& operator<<( std::ostream& os, const AForm& f );
