/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:13:19 by herz              #+#    #+#             */
/*   Updated: 2024/10/15 16:44:50 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "Bureaucrat.fwd.hpp"
#include "Bureaucrat.hpp"

#ifndef RED
# define RED	"\033[0;31m"
#endif
#ifndef GREEN
# define GREEN	"\033[1;32m"
#endif
#ifndef YELLOW
# define YELLOW	"\033[1;33m"
#endif
#ifndef RESET
# define RESET	"\033[0m"
#endif

class	Form {
	private:
		const std::string	_name;
		bool				_sign;
		const unsigned int	_sGrade;
		const unsigned int	_eGrade;
	public:
		Form( void );
		Form( std::string name, unsigned int sGrade, unsigned int eGrade );
		~Form( void );
		Form( const Form& );
		Form& operator=( const Form& );

		std::string		getName( void ) const;
		bool			getSign( void ) const;
		unsigned int	getSGrade( void ) const;
		unsigned int	getEGrade( void ) const;

		void			beSigned( Bureaucrat b );


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
};

std::ostream& operator<<( std::ostream& os, const Form& f );
