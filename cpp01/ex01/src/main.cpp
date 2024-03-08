/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:41:42 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/08 12:54:31 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"
#include <iostream>

int	main(int argc, char *argv[]) {
	Zombie	*zombies;

	if (argc != 1)
		return (0);
	zombies = zombieHorde(5, "Pepito");
	for (size_t i = 0; i < 5; i++) {
		zombies[i].announce();
	}
	delete[]	zombies;
	(void)argv;
	return (0);
}