/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:33:18 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/15 12:55:48 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ClapTrapDefs.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap	c("clap");
	ScavTrap	s("scav");
	FragTrap	f("frag");

	std::cout << std::endl;
	c.attack("scav");
	s.takeDamage(c.getAtk());
	std::cout << std::endl;
	s.attack("frag");
	f.takeDamage(s.getAtk());
	std::cout << std::endl;
	f.attack("clap");
	c.takeDamage(f.getAtk());
	std::cout << std::endl;
	f.highFivesGuys();
	std::cout << std::endl;
	c.beRepaired(5);
	c.attack("scav");
	std::cout << std::endl;
	f.attack("scav");
	s.takeDamage(f.getAtk());
	std::cout << std::endl;
	s.guardGate();
	std::cout << std::endl;
	return (0);
}
