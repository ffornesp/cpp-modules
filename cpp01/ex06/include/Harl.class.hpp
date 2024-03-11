/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:52:53 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/11 17:47:12 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CLASS_H
# define HARL_CLASS_H

# ifndef DEBUG
#  define DEBUG	0
# endif
# ifndef INFO
#  define INFO	1
# endif
# ifndef WARNING
#  define WARNING	2
# endif
# ifndef ERROR
#  define ERROR	3
# endif

#include <string>

class Harl
{
	private:
		std::string	_levels[4];
		void	(Harl::*_functionPtr[4])( void );
		void	_debug( void );
		void	_info( void );
		void	_warning( void );
		void	_error( void );
	public:
		Harl( void );
		~Harl( void );
		void	complain(std::string level);
};

#endif