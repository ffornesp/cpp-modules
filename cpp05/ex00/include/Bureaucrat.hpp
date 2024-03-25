/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:15:08 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/25 14:05:50 by ffornes-         ###   ########.fr       */
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
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& b );
