/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/20 15:34:05 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	MateriaSource : public IMateriaSource {
	private:
	protected:
	public:
		MateriaSource( void );
		virtual ~MateriaSource( void );
		MateriaSource( const MateriaSource& old );
		MateriaSource& operator=( const MateriaSource& );

		virtual void		learnMateria( AMateria* );
		virtual AMateria*	createMateria( std::string const & type );
};
