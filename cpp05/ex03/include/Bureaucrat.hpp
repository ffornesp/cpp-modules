/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:15:08 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/09 17:16:28 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "AForm.fwd.hpp"
#include "AForm.hpp"

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

		void			signForm( AForm& f ) const ;
		void			executeForm( AForm const & form ) const ;

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
