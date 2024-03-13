/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:11:19 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/13 11:26:23 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_H
# define WEAPON_H

#include <string>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon( std::string type );
		~Weapon( void );
		const std::string& 	getType( void );
		bool				setType( std::string type );
};

#endif