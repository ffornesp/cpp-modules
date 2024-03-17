/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:33:18 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/15 15:33:47 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ClapTrapDefs.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap	c("clap");
//	ScavTrap	s("scav");
//	FragTrap	f("frag");
	DiamondTrap	d("Morad");
	// DiamondTrap

	std::cout << std::endl;
	d.whoAmI();
	std::cout << std::endl;
	d.attack("clap");
	c.takeDamage(d.getAtk());
	std::cout << std::endl;
	d.guardGate();
	d.highFivesGuys();
	std::cout << std::endl;
	d.beRepaired(5);
	std::cout << std::endl;

	return (0);
}
