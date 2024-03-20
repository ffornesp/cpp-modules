/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/20 12:08:32 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.fwd.hpp"
#include <string>

class	ICharacter {
	private:
	protected:
		std::string	_name;
		AMateria*	_inventory[4];
	public:
		virtual ICharacter( void );
		virtual ~ICharacter( void );
		ICharacter( const ICharacter& old );
		ICharacter& operator=( const ICharacter& old );

		virtual std::string const & getName() const = 0;

		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};
