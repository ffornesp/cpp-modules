/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:41:42 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/12 10:04:14 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main() {
	Zombie	*zombies;

	zombies = zombieHorde(5, "Pepito");
	for (size_t i = 0; i < 5; i++) {
		zombies[i].announce();
	}
	delete[]	zombies;
	return (0);
}
