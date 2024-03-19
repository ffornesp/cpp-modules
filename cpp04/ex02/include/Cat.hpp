/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:11:52 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 18:36:06 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat : public AAnimal {
	private:
		Brain *_brain;
	public:
		Cat( void );
		Cat( std::string name );
		~Cat( void );
		Cat( const Cat& old );
		Cat& operator=( const Cat& old );

		virtual void	makeSound( void ) const;
};
