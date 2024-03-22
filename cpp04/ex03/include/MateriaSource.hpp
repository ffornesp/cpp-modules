/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/22 14:46:54 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include <string>

class	MateriaSource : public IMateriaSource {
	private:
		AMateria*		_mats[4];
		unsigned int	_amount;
	public:
		MateriaSource( void );
		virtual ~MateriaSource( void );
		MateriaSource( const MateriaSource& old );
		MateriaSource& operator=( const MateriaSource& );

		virtual void		learnMateria( AMateria* );
		virtual AMateria*	createMateria( std::string const & type );

		void	deleteMaterias( void );
};
