/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:41:42 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/11 17:10:50 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"
#include <iostream>

int	main() {
	Zombie	*zombie;

	zombie = newZombie("Cacahuete");
	zombie->announce();
	
	randomChump("Nectarina");

	delete zombie;
	return (0);
}
