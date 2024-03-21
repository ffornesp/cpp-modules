/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/21 12:44:58 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.fwd.hpp"
#include "ICharacter.hpp"
#include <string>

class	AMateria {
	private:
	protected:
		std::string	_type;
	public:
		AMateria( void );
		AMateria( std::string const type );
		virtual ~AMateria( void );
		AMateria( const AMateria& old );
		AMateria& operator=( const AMateria& );

		std::string const & getType( void ) const;
		virtual AMateria* clone() const = 0;
		virtual void	use(ICharacter& target);
};
