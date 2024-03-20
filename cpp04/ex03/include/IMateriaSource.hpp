/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/20 17:04:29 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <string>

class	IMateriaSource {
	private:
	protected:
		std::string		_type;
		AMateria*		_mats[4];
		unsigned int	_amount;
	public:
		IMateriaSource( void );
		virtual ~IMateriaSource( void );
		IMateriaSource( const IMateriaSource& old );
		IMateriaSource& operator=( const IMateriaSource& );

		virtual void		learnMateria( AMateria* ) = 0;
		virtual AMateria*	createMateria( std::string const & type ) = 0;
};
