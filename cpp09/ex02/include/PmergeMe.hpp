/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:07:53 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/31 17:27:57 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <deque>
#include <cstdlib>
#include <iostream>

class	ChainLink {
	private:
		int	_first;
		int	_second;
	public:
		ChainLink( void );
		ChainLink( int&, int& );
		~ChainLink( void );
		ChainLink( const ChainLink& );
		ChainLink& operator=( const ChainLink& );

		int		getFirst( void ) const ;
		int		getSecond( void ) const ;
		void	setFirst( int n );
		void	setSecond( int n );

		bool	compareElements( void ) const ;
		bool	compareFirst( const ChainLink ) const;

		void	swapElements( void );
};

std::ostream& operator<<( std::ostream&, const ChainLink& );

void	sort( std::deque< ChainLink >& deq, std::list< ChainLink >& list );

template< typename T >
void	fillContainer( T& t, char *argv[] ) {
	ChainLink	link;
	bool		flag;
	int			content[2];

	for ( int i = 1; argv[ i ] != NULL; i++ ) {
		if ( !flag ) {
			content[ 0 ] = atoi( argv[ i ] );
			flag = true;
		} else {
			content[ 1 ] = atoi( argv[ i ] );
			ChainLink	link( content[ 0 ], content[ 1 ] );
			t.push_back( link );
			flag = false;
		}
	}
}

template< typename T >
void	printContent( T& t ) {
	for ( typename T::iterator it = t.begin(); it != t.end(); it++ )
		std::cout << *it << " ";
	std::cout << std::endl;
}

//	Returns an iterator pointing to the first element of t which contains a _second value that
// does not compare less than the _second value contained in c.
template< typename T >
typename T::iterator ChainLink_lower_bound( T& t, ChainLink c ) {
	for ( typename T::iterator it = t.begin(); it != t.end(); it++ ) {
		ChainLink	link( *it );
		if ( link.getSecond() > c.getSecond() )
			return it;
	}
	return t.end();
}