/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:11:23 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/12 10:07:03 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"

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
