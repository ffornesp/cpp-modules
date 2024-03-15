/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:33:01 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/15 11:09:03 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hP;
		int			_energy;
		int			_atk;
	public:
		ClapTrap( void );								// Canonical
		ClapTrap( std::string name );
		~ClapTrap( void );								// Canonical
		ClapTrap( const ClapTrap& old );				// Canonical
		ClapTrap&	operator=(const ClapTrap& old );	// Canonical

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
