/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/21 17:24:18 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.fwd.hpp"
#include "ICharacter.fwd.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class	Character : public ICharacter {
	private:
		std::string		_name;
		AMateria*		_inventory[4];
		unsigned int	_amount;
	public:
		Character( void );
		Character( std::string name );
		~Character( void );
		Character( const Character& old );
		Character& operator=( const Character& old );

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use( int idx, ICharacter& target );
};
