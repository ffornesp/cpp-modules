/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:48:13 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/09 17:16:43 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
# ifndef PRESIDENTIAL_PARDON
#  define PRESIDENTIAL_PARDON	0
# endif
# ifndef ROBOTOMY_REQUEST
#  define ROBOTOMY_REQUEST	1
# endif
# ifndef SHRUBBERY_CREATION
#  define SHRUBBERY_CREATION	2
# endif

class	Intern {
	private:
		
	public:
		Intern( void );
		~Intern( void );
		Intern( const Intern& );
		Intern& operator=( const Intern& );
	
		AForm*	makeForm( std::string name, std::string target );
};
