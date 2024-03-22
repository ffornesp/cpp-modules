/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:07:41 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 10:07:38 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {
	private:
		Brain *_brain;
	public:
		Dog( void );
		~Dog( void );
		Dog( const Dog& old );
		Dog& operator=( const Dog& old );

		virtual void	makeSound( void ) const;
};
