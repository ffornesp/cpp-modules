/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:07:41 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 09:35:48 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class	Dog : public Animal {
	private:
	public:
		Dog( void );
		Dog( std::string name );
		~Dog( void );
		Dog( const Dog& old );
		Dog& operator=( const Dog& old );

		virtual void	makeSound( void ) const;
};
