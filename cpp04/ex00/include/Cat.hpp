/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:11:52 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/18 17:34:49 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class	Cat : public Animal {
	private:
	public:
		Cat( void );
		Cat( std::string name );
		~Cat( void );
		Cat( const Cat& old );
		Cat& operator=( const Cat& old );

		void		makeSound( void ) const;
		std::string	getType( void ) const;
};
