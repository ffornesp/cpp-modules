/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:41:42 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/08 12:08:38 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"
#include <iostream>

int	main(int argc, char *argv[]) {
	if (argc != 1)
		return (0);

	Zombie	*zombie;

	zombie = newZombie("Cacahuete");
	zombie->announce();
	
	randomChump("Nectarina");

	delete zombie;
	(void)argv;
	return (0);
}