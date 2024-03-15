/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:30:27 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/15 11:07:38 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef SCAVTRAP_H
// # define SCAVTRAP_H
#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
	
	public:
		ScavTrap( void );						// Canonical
		~ScavTrap( void );						// Canonical
		// ScavTrap( const ScavTrap& old );		// Canonical
		// ScavTrap& operator=(const ScavTrap& );	// Canonical

		void	guardGate();
};

// #endif