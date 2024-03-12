/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:52:53 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/11 16:58:33 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

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