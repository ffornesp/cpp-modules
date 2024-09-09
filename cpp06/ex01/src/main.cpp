/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:31:47 by ffornes-          #+#    #+#             */
/*   Updated: 2024/09/09 13:21:50 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main( void ) {
	Data	data;
	void	*v1;
	void	*v2;

	data.i = 0;
	v1 = &data;
	v2 = Serializer::deserialize( Serializer::serialize( &data ));
	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	return ( 0 );
}
