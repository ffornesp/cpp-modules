/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/22 11:44:30 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	AAnimal {
	
	private:
	protected:
		std::string	_type;
	public:
		AAnimal( void );
		virtual ~AAnimal( void );
		AAnimal( const AAnimal& old );
		AAnimal& operator=( const AAnimal& );

		virtual void	makeSound( void ) const = 0;
		std::string		getType( void ) const;
};
