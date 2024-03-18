/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:39:54 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/18 11:52:14 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
protected:
	static const unsigned int	_classHp = 100;
	static const unsigned int	_classEnergy = 100;
	static const unsigned int	_classAtk = 30;
public:
	FragTrap( void );
	FragTrap( std::string name );
	~FragTrap( void );
	FragTrap( const FragTrap& old );
	FragTrap& operator=( const FragTrap& old );

	void	highFivesGuys( void );
};
