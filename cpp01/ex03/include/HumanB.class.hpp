/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:11:21 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/08 14:12:24 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_H
# define HUMANB_CLASS_H

#include "Weapon.class.hpp"

class HumanB
{
	private:
		Weapon _weapon;
		std::string	_name;
	public:
		HumanB( std::string name );
		~HumanB( void );
		void	attack();
		bool	setWeapon( Weapon weapon );
};

#endif