/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:11:21 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/12 10:06:52 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *_weapon;
		std::string	_name;
	public:
		HumanB( std::string name );
		~HumanB( void );
		void	attack();
		bool	setWeapon( Weapon &weapon );
};

#endif
