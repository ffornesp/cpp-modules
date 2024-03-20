/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 18:34:30 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	AMateria {
	private:
	protected:
	public:
		AMateria( void );
		AMateria( std::string const & type );
		virtual ~AMateria( void );
		AMateria( const AMateria& old );
		AMateria& operator=( const AMateria& );

		virtual AMateria* clone() const = 0;
		virtual void	use(ICharacter& target);
};
