/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:11 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/31 18:17:30 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <deque>
#include <list>

void	sort( std::deque< int > myDeque, std::list< int > myList ) {
	sortPairs( myDeque );
	
//	It would be wise to create a struct that contains 2 numbers and the
//	deques and lists containing that struct.
//	The main reason for that is to be able to work with the pairs since
//	once you have them sorted by pairs you kinda treat them as 2 different
//	chains. This way it's easier to work with a "main chain" while having
//	the hypothetical "auxiliary chain" tied to it.

//	Once we have our main chain with the custom struct that contains the 2
//	numbers, we should sort the main chain just comparing the first number
//	but moving both.

//	Once we are done with that, it's the moment to split the main chain into
//	2 chains, the main chain and the auxiliary chain. They contain single ints 
//	instead of our struct with 2 ints.

//	Then we are able to use jacobs numbers to insert the second chain into
//	the main one.

	sortPairs( myList );
}
