/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:29:29 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/21 18:53:21 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstring>
#include <vector>

void	RPN( std::string str ) {
	std::vector< int >	numbers;
	std::vector< char >	operators;

	for ( std::string::iterator it = str.begin(); it != str.end(); it++ ) {
		if ( strchr( "+-/*", *it ) )
			operators.push_back( *it );
		else
			numbers.push_back( *it - '0' );
	}

	std::cout << "Operators: ";
	for ( size_t i = 0; i < operators.size(); i++ )
		std::cout << operators[ i ] << " ";
	std::cout << std::endl;
	std::cout << "Digits: ";
	for ( size_t i = 0; i < numbers.size(); i++ )
		std::cout << numbers[ i ] << " ";
	std::cout << std::endl;
}
