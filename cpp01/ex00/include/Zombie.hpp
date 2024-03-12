/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:41:36 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/12 10:02:36 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {
	
	private:
		std::string	_name;
	public:
		Zombie( std::string name );
		~Zombie( void );
		void	announce( void );
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif