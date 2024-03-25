/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:15:08 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/25 17:04:16 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

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
		bool			setGrade( unsigned int grade );

		bool			increment( void );
		bool			decrement( void );
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& b );
