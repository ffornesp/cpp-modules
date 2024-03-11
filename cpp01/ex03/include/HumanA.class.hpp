/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:11:23 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/11 11:23:27 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_H
# define HUMANA_CLASS_H

#include "Weapon.class.hpp"

class HumanA
{
	private:
		Weapon&		_weapon;
		std::string	_name;
	public:
		HumanA( std::string name, Weapon& weapon );
		~HumanA();
		void	attack();
		std::string	getName();
		bool	setWeapon( Weapon weapon );
};

#endif
