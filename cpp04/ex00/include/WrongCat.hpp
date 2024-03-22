/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:11:52 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/22 14:41:17 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
	private:
	public:
		WrongCat( void );
		~WrongCat( void );
		WrongCat( const WrongCat& old );
		WrongCat& operator=( const WrongCat& old );

		void	makeSound( void ) const;
};
