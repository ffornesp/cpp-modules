/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:29:29 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/28 19:31:35 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	RPN( std::string str ) {
	std::vector< long double >		numbers;
	std::vector< long double >		result;
	std::vector< long double >::iterator	vit;

	for ( std::string::iterator it = str.begin(); it != str.end(); ++it ) {
		if ( !strchr( "+-/*", *it ) ) {
			//std::cout << "Pushing [" << *it << "] into numbers" << std::endl;
			numbers.push_back( *it - '0' );
		}
		else {
			//std::cout << "Found operator: " << *it << std::endl;
			if ( numbers.size() > 1 ) {
				// Print operation
				//std::cout << "[" << numbers[0] << "] " << *it << " [" << numbers[1] << "]";

				if ( calculate( numbers[0], numbers[1], *it ) ) {
					vit = numbers.begin();
					vit++;
					numbers.erase( vit );
					//std::cout << " = " << numbers.front() << std::endl;
				} else
					return ;
			}
			else if ( numbers.size() == 1 ) {
				// Print operation
				//std::cout << "[" << result[ result.size() - 1 ] << "] " << *it << " [" << numbers[0] << "]";

				if ( calculate( result[ result.size() - 1 ], numbers[0], *it ) ) {
					vit = numbers.begin();
					numbers.erase( vit );
				} else
					return ;
				// Print result
				//std::cout << " = " << result[ result.size() - 1 ] << std::endl;
			}
			else if ( result.size() > 1 ) {
				// Print operation
				//std::cout << "[" << result[ result.size() - 2 ] << "] " << *it << " [" << result.back() << "]";

				if ( calculate( result[ result.size() - 2 ], result.back() , *it ) ) {
					result.pop_back();
				} else
					return ;
				// Print result
				//std::cout << " = " << result[ result.size() - 2 ] << std::endl;
			}
			if ( numbers.size() == 1 ) {
				std::string::iterator	ite = it;
				ite++;
				if ( ite != str.end() && !strchr( "+-/*", *ite ) ) {
					result.push_back( numbers.front() );
					numbers.erase( numbers.begin(), numbers.end() );
				}
			}
		}
	}
	std::cout << std::fixed << result.front() << std::endl;
}
