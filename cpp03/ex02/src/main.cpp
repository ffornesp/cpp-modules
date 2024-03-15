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
	s.takeDamage(10);
	std::cout << std::endl;
	s.attack("frag");
	f.takeDamage(99);
	std::cout << std::endl;
	f.attack("clap");
	c.takeDamage(100);
	std::cout << std::endl;
	f.highFivesGuys();
	std::cout << std::endl;
	c.beRepaired(5);
	c.attack("scav");
	std::cout << std::endl;
	s.guardGate();
	f.attack("scav");
	s.takeDamage(100);
	s.guardGate();
	std::cout << std::endl;
	return (0);
}