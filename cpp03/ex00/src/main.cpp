/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:33:18 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/18 09:10:39 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ClapTrapDefs.hpp"
#include <iostream>

int	main()
{
	ClapTrap	r("Robo");
	ClapTrap	h("Human");

	std::cout << std::endl;
	r.attack("Human");
	h.takeDamage(r.getAtk());
	std::cout << std::endl;
	h.beRepaired(5);
	std::cout << std::endl;
	h.attack("Robo");
	r.takeDamage(h.getAtk());
	std::cout << std::endl;
	r.beRepaired(10);
	std::cout << std::endl;
	h.attack("Robo");
	r.takeDamage(h.getAtk());
	std::cout << std::endl;
	r.attack("Human");
	h.takeDamage(r.getAtk());
	std::cout << std::endl;
	
	return (0);
}
