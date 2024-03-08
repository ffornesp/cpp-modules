/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:41:36 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/08 12:44:36 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

#include <string>

class Zombie {
	
	private:
		std::string	_name;
	public:
		Zombie( void );
		~Zombie( void );
		void	announce( void );
		bool	setName( std::string name );
};

Zombie	*zombieHorde( int N, std::string name );

#endif