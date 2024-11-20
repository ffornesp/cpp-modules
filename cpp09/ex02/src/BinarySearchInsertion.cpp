/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchInsertion.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:31:06 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/20 15:48:11 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const int	jacobsthalNumbers[15] = { 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461 }; 

static void		fillChain( std::deque< int >& dst, std::deque< int > src, size_t groupSize, size_t& groups );
static void		handleLeftovers( std::deque< int >& src, std::deque< int >& leftovers, std::deque< int >::iterator& it );
static void		jacobsthalInsertion( std::deque< int >& mainChain, std::deque< int > src, size_t groupSize, size_t groups );
static size_t	binarySearch( std::deque< int > src, size_t groupSize, int value, int limitValue );
static int		getIndex( double index, size_t groupSize );
static size_t	getLastIndex( std::deque< int > src, size_t groupSize, int limitValue );

void	binarySearchInsertion( std::deque< int >& src, size_t groupSize ) {
	std::deque< int >			mainChain;	
	std::deque< int >			leftovers;
	std::deque< int >::iterator	leftoversIt;
	size_t						groups = src.size() / groupSize;
//	size_t						oddIndex = 0;

/*
	if ( groups & 1 ) {
		oddIndex = groups;
		leftoversIt = src.begin() + ( groups * groupSize );
		groups--;
	} else */
		leftoversIt = src.begin() + ( groups * groupSize );

	fillChain( mainChain, src, groupSize, groups );
	handleLeftovers( src, leftovers, leftoversIt );
	jacobsthalInsertion( mainChain, src, groupSize, groups );
/*	//	Inserts the last group in case that the group doesn't have a pair aka it's leftover 
	if ( oddIndex > 0 ) {
		std::deque< int >::iterator	first = src.begin() + groupSize * ( oddIndex - 1 );
		std::deque< int >::iterator	second = first + groupSize;
		std::deque< int >::iterator	pos = mainChain.begin() + binarySearch( mainChain, groupSize, *( second - 1 ), -1 );
		mainChain.insert( pos, first, second );
	}
*/

	src = mainChain;
	// Must add the leftover numbers that were erased at the beggining of this function
	if ( leftovers.size() > 0 )
		src.insert( src.end(), leftovers.begin(), leftovers.end() );

	// DEBUG
	if ( groupSize > 1 ) {
		std::cout << YELLOW << "FINISH\t\t" << DEFAULT;
		printGroups( mainChain, groupSize );
	}
}

//	Fills deque 'dst' with all the values already sorted ( the odd numbers ) found in src
static void	fillChain( std::deque< int >& dst, std::deque< int > src, size_t groupSize, size_t& groups ) {
	std::deque< int >::iterator pos = src.begin() + groupSize;
	for ( size_t count = groups * 0.5f; count > 0; count-- ) {
		dst.insert( dst.end(), pos, pos + groupSize );
		pos += groupSize * 2;
		groups--;
	}
} 

static void	handleLeftovers( std::deque< int >& src, std::deque< int >& leftovers, std::deque< int >::iterator& it ) {
	if ( it != src.end() ) {
		leftovers.insert( leftovers.begin(), it, src.end() );
		src.erase( it, src.end() );
	}
}

static void	jacobsthalInsertion( std::deque< int >& mainChain, std::deque< int > src, size_t groupSize, size_t groups ) {
 	size_t	n = 0;
	int		jacob = jacobsthalNumbers[ n ] * 2;
	int		previousJacob = 0;
	while ( groups ) {
		if ( jacob == 0 ) {
			mainChain.insert( mainChain.begin(), src.begin(), src.begin() + groupSize );
			groups--;
			// DEBUG
			printInfo( src, mainChain, groupSize );
		}
		while ( jacob > previousJacob ) {
			if ( ( groupSize * jacob * 2 + groupSize - groupSize ) < src.size() ) {
				std::deque< int >::iterator	first = src.begin() + groupSize * jacob * 2;
				std::deque< int >::iterator	second = first + groupSize;

				int	valueOfPair = ( groupSize * jacob * 2 ) + groupSize - 1 + groupSize;
				if ( valueOfPair > static_cast< int >( src.size() ) )
					valueOfPair = -1;
				else
					valueOfPair = src[ valueOfPair ];

				std::deque< int >::iterator	pos = mainChain.begin() + binarySearch( mainChain, groupSize, *( second - 1 ), valueOfPair );
				mainChain.insert( pos, first, second );
//				printInfo( src, mainChain, groupSize );
				groups--;
			}
			jacob--;
		}
		if ( groups ) {
			previousJacob += jacobsthalNumbers[ n++ ] * 2;
			jacob = previousJacob + jacobsthalNumbers[ n ] * 2;
		}
	} 
}

static size_t	binarySearch( std::deque< int > src, size_t groupSize, int value, int limitValue ) {
	size_t	low = 1;
	size_t	high = getLastIndex( src, groupSize, limitValue );

	size_t	count = 0;
	while ( low < high ) {
		count++;
		size_t	mid = ( high - low ) / 2 + low;
//		std::cout << "LOW: " << low << " MID: " << mid << " HIGH: " << high << std::endl;
		
		if ( value > src[ getIndex( mid, groupSize ) ] ) {
			if ( mid < high )
				low = mid + 1;
			else
				low = mid;
		}
		else {
			if ( mid > low )
				high = mid - 1;
			else
				high = low;
		}
	}
	size_t	index = 0;
	count++;
	if ( value < src[ getIndex( low, groupSize ) ] )
		index = getIndex( low, groupSize ) - groupSize + 1;
	else
		index = getIndex( high, groupSize ) + 1;
	std::cout << "CHECK COUNT: " << count << std::endl;
	return index;
}

static int	getIndex( double index, size_t groupSize ) {
	return ( index - 1 ) * groupSize + groupSize - 1;
}

static size_t	getLastIndex( std::deque< int > src, size_t groupSize, int limitValue ) {
	if ( limitValue >= 0 ) {
 		for ( size_t i = 0; i < src.size(); i++ )
			if ( src[ i ] == limitValue )
				return i / groupSize;
	}
	return src.size() / groupSize;
}
