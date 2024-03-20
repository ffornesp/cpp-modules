/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/20 17:10:43 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class	Character : public ICharacter {
	private:
	protected:
	public:
		Character( void );
		Character( std::string name );
		virtual ~Character( void );
		Character( const Character& old );
		Character& operator=( const Character& old );

		virtual std::string const & getName() const;
		
		std::string	getName( void );
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, Character& target);
};
