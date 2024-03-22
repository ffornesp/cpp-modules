/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 09:39:22 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Animal {
	
	private:
	protected:
		std::string	_type;
	public:
		Animal( void );
		virtual ~Animal( void );
		Animal( const Animal& old );
		Animal& operator=( const Animal& );

		virtual void	makeSound( void ) const;
		std::string		getType( void ) const;
};
