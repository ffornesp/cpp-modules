/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:11:52 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 09:35:33 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class	Cat : public Animal {
	private:
	public:
		Cat( void );
		~Cat( void );
		Cat( const Cat& old );
		Cat& operator=( const Cat& old );

		virtual void	makeSound( void ) const;
};
