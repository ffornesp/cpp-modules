/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:00:52 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 10:28:36 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain( void ) {
	std::cout << "Brain default constructor called" << std::endl;
}
Brain::~Brain( void ) {
	std::cout << "Brain destructor called" << std::endl;
}
Brain::Brain( const Brain& old ) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = old;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = old._ideas[i];
}
Brain& Brain::operator=( const Brain& old ) {
	std::cout << "Brain copy assignemnt operator" << std::endl;
	if (this != &old) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = old._ideas[i];
	}
	return (*this);
}
