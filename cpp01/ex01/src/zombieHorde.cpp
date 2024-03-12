/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:18:29 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/12 10:04:15 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie	*zombieHorde( int N, std::string name ) {
	Zombie	*zombie_horde = new Zombie[N];
	for (size_t i = 0; i < (size_t)N; i++) {
		zombie_horde[i].setName(name);
	}
	return (zombie_horde);
}