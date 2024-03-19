/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:57:16 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 10:09:21 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain( void );
		~Brain( void );
		Brain( const Brain& old );
		Brain& operator=( const Brain& );
};
