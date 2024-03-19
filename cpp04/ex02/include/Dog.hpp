/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:07:41 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 18:36:15 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog : public AAnimal {
	private:
		Brain *_brain;
	public:
		Dog( void );
		Dog( std::string name );
		~Dog( void );
		Dog( const Dog& old );
		Dog& operator=( const Dog& old );

		virtual void	makeSound( void ) const;
};
