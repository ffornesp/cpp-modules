/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:13:19 by herz              #+#    #+#             */
/*   Updated: 2024/06/12 12:46:31 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "Bureaucrat.fwd.hpp"
#include "Bureaucrat.hpp"

class	Form {
	private:
		const std::string	_name;
		bool				_sign;
		const unsigned int	_sGrade;
		const unsigned int	_eGrade;
	public:
		Form( std::string name, unsigned int sGrade, unsigned int eGrade );
		~Form( void );
		Form( const Form& );
		Form& operator=( const Form& );

		std::string		getName( void ) const;
		bool			getSign( void ) const;
		unsigned int	getSGrade( void ) const;
		unsigned int	getEGrade( void ) const;

		void			beSigned( Bureaucrat b );

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
};

std::ostream& operator<<( std::ostream& os, const Form& f );
