/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:33:18 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/15 11:08:01 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ClapTrapDefs.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ScavTrap	r;
	// ScavTrap	r("Robo");
	ClapTrap	h("Human");

	std::cout << std::endl;
	r.attack("human");
	h.takeDamage(5);
	std::cout << std::endl;
	h.beRepaired(5);
	std::cout << std::endl;
	h.attack("robo");
	r.takeDamage(10);
	std::cout << std::endl;
	r.beRepaired(10);
	std::cout << std::endl;
	h.attack("robo");
	r.takeDamage(10);
	std::cout << std::endl;
	r.attack("human");
	std::cout << std::endl;
	
	return (0);
}