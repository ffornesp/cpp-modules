/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:33:54 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 09:47:58 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main( void ) {
	const Animal* 		meta = new Animal();
	const WrongAnimal*	wrong = new WrongAnimal();
	const Animal* 		j = new Dog();
	const Animal* 		i = new Cat();
	const WrongAnimal*	h  = new WrongCat();

	std::cout << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << meta->getType() << std::endl;
	std::cout << wrong->getType() << std::endl;
	std::cout << h->getType() << std::endl;
	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	wrong->makeSound();
	h->makeSound();
	std::cout << std::endl;


	delete meta;
	delete j;
	delete i;
	delete h;
	return (0);
}
