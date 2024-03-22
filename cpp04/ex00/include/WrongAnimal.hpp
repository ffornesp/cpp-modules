
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/18 17:34:43 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	WrongAnimal {
	private:

	protected:
		std::string			_type;
	public:
		WrongAnimal( void );
		~WrongAnimal( void );
		WrongAnimal( const WrongAnimal& old );
		WrongAnimal& operator=( const WrongAnimal& );

		void	makeSound( void ) const;
		std::string		getType( void ) const;
};
