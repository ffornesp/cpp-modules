/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:30:27 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/18 11:52:27 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap
{
	private:
	protected:
		static const unsigned int	_classHp = 100;
		static const unsigned int	_classEnergy = 50;
		static const unsigned int	_classAtk = 20;
	public:
		ScavTrap( void );							// Canonical
		ScavTrap( std::string name );
		~ScavTrap( void );							// Canonical
		ScavTrap( const ScavTrap& old );			// Canonical
		ScavTrap& operator=(const ScavTrap& old );	// Canonical
		
		void	attack( std::string target );
		void	guardGate( void );
};

// #endif
