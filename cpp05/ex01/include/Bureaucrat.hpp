/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:15:08 by ffornes-          #+#    #+#             */
/*   Updated: 2024/06/10 12:12:40 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "Form.fwd.hpp"
#include "Form.hpp"

class	Bureaucrat {
	private:
		const std::string	_name;
		unsigned int		_grade;
	public:
		Bureaucrat( std::string name, unsigned int grade );
		~Bureaucrat( void );
		Bureaucrat( const Bureaucrat& );
		Bureaucrat& operator=( const Bureaucrat& );

		std::string		getName( void ) const;
		unsigned int	getGrade( void ) const;
		void			setGrade( unsigned int grade );

		void			increment( void );
		void			decrement( void );

		void			signForm( Form f );

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

std::ostream& operator<<( std::ostream& os, const Bureaucrat& b );
