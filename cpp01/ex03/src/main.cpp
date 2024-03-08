/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:11:45 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/08 14:16:21 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.class.hpp"
#include "HumanA.class.hpp"
#include "HumanB.class.hpp"

int main()
{
	Weapon	club = Weapon("crude spiked club");

	HumanA	bob("Bob", &club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	Weapon sword = Weapon("crude spiked club");

	HumanB	jim("Jim");
	jim.setWeapon(sword);
	jim.attack();
	sword.setType("some other type of club");
	jim.attack();
	return 0;
}