/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:39:54 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/15 12:51:20 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	
public:
	FragTrap( void );
	FragTrap( std::string name );
	~FragTrap( void );
	FragTrap( const FragTrap& old );
	FragTrap& operator=( const FragTrap& old );

	void	highFivesGuys( void );
};