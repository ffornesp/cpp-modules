/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:15:08 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/15 16:45:45 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "Form.fwd.hpp"
#include "Form.hpp"

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

class	Bureaucrat {
	private:
		const std::string	_name;
		unsigned int		_grade;
	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, unsigned int grade );
		~Bureaucrat( void );
		Bureaucrat( const Bureaucrat& );
		Bureaucrat& operator=( const Bureaucrat& );

		std::string		getName( void ) const;
		unsigned int	getGrade( void ) const;
		void			setGrade( unsigned int grade );

		void			increment( void );
		void			decrement( void );

		void			signForm( Form& f ) const ;

	class	GradeTooLowException : public std::range_error {
		public:
			GradeTooLowException( const std::string &msg );
	};

	class	GradeTooHighException : public std::range_error {
		public:
			GradeTooHighException( const std::string &msg );
	};
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& b );
