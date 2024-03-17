/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:33:18 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/15 12:38:58 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ClapTrapDefs.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ScavTrap	r;
	ScavTrap	h("Human");

	std::cout << std::endl;

	r.attack("Human");
	h.takeDamage(r.getAtk());
	std::cout << std::endl;

	h.beRepaired(25);
	std::cout << std::endl;

	h.attack("??");
	r.takeDamage(h.getAtk());
	std::cout << std::endl;

	r.beRepaired(10);
	std::cout << std::endl;

	h.attack("??");
	r.takeDamage(h.getAtk());
	std::cout << std::endl;

	r.attack("Human");
	h.takeDamage(r.getAtk());
	std::cout << std::endl;
	
	r.guardGate();
	h.guardGate();
	std::cout << std::endl;
	
	return (0);
}
