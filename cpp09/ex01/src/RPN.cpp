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
#include <cmath>
#include <limits>
#include <cfloat>

static void	fillVectors( std::string str, std::vector< int >& numbers, std::vector< char >& operators );
static bool	calculate( long double& n1, int n2, char operation );
static bool	infiniteCheck( long double n );
static bool	additionCheck( long double n1, int n2 );
static bool	subtractionCheck( long double n1, int n2 );
static bool	multiplicationCheck( long double n1, int n2 );
static bool	divisionCheck( long double n1, int n2 );
static bool	printError( std::string msg );

void	RPN( std::string str ) {
	std::vector< int >	numbers;
	std::vector< char >	operators;

	fillVectors( str, numbers, operators );

	long double	result = numbers[0];
	for ( size_t i = 0; i < operators.size(); i++ )
		if ( !calculate( result, numbers[ i + 1 ], operators[ i ] ) )
			return ;
	
	std::cout << std::fixed << result << std::endl;
}

static void	fillVectors( std::string str, std::vector< int >& numbers, std::vector< char >& operators ) {
	for ( std::string::iterator it = str.begin(); it != str.end(); it++ ) {
		if ( strchr( "+-/*", *it ) )
			operators.push_back( *it );
		else
			numbers.push_back( *it - '0' );
	}
}

static bool	calculate( long double& n1, int n2, char operation ) {
	switch ( operation ) {
		case '+':
			if ( !additionCheck( n1, n2 ) )
				return false;
			n1 = n1 + n2;
			break ;
		case '-':
			if ( !subtractionCheck( n1, n2 ) )
				return false;
			n1 = n1 - n2;
			break ;
		case '*':
			if ( !multiplicationCheck( n1, n2 ) )
				return false;
			n1 = n1 * n2;
			break ;
		case '/':
			if ( !divisionCheck( n1, n2 ) )
				return false;
			n1 = n1 / n2;
			break ;
	}
	if ( std::isnan( n1 ) )
		return printError( "NaN" );
	return true;
}

static bool	infiniteCheck( long double n ) {
	if ( std::isinf( n ) ) {
		if ( std::signbit( n ) )
			return printError( "-inff." );
		else
			return printError( "inff." );
    }
	return true;
}

static bool	additionCheck( long double n1, int n2 ) {
	if ( n1 > 0 && n2 > 0 && n1 > ( LDBL_MAX - n2 ) )
		return printError( "Overflow: addition result is too big." );
	if ( n1 < 0 && n2 < 0 && n1 < ( -LDBL_MAX - n2 ) )
		return printError( "Underflow: addition result is too small." );
	return true;
}

static bool	subtractionCheck( long double n1, int n2 ) {
	if ( n1 > 0 && n2 < 0 && n1 > ( LDBL_MAX + n2 ) )
		return printError( "Overflow: addition result is too big." );
	if ( n1 < 0 && n2 > 0 && n1 < ( -LDBL_MAX + n2 ) )
		return printError( "Underflow: addition result is too small." );
	return true;
}

static bool	multiplicationCheck( long double n1, int n2 ) {
	if ( !infiniteCheck( n1 * n2 ) )
		return false;
	if ( n1 > 0 && n2 > 0 && n1 > ( LDBL_MAX / n2 ))
		return printError( "Overflow: multiplication result is too big." );
	else if ( n1 < 0 && n2 < 0 && n1 < ( LDBL_MAX / n2 ))
		return printError( "Overflow: multiplication result is too big." );
	else if ( n1 > 0 && n2 < 0 && n1 < ( -LDBL_MAX / 2 ))
		return printError( "Underflow: multiplication result is too small." );
	else if ( n1 < 0 && n2 > 0 && n1 < ( -LDBL_MAX / 2 ))
		return printError( "Underflow: multiplication result is too small." );
	return true;
}

static bool	divisionCheck( long double n1, int n2 ) {
	if ( n2 == 0 )
		return printError( "Can't divide by 0." );
	if ( !infiniteCheck( n1 / n2 ) )
		return false;
	if ( n1 > 0 && n2 > 0 && n1 > ( LDBL_MAX / n2 ) )
		return printError( "Overflow: division result is too big." );
	else if ( n1 < 0 && n2 < 0 && n1 < ( LDBL_MAX / n2 ) )
		return printError( "Overflow: division result is too big." );
	else if ( n1 > 0 && n2 < 0 && n1 < ( -LDBL_MAX / n2 ) )
		return printError( "Underflow: divison result is too small." );
	else if ( n1 < 0 && n2 > 0 && n1 < ( -LDBL_MAX / n2 ) )
		return printError( "Underflow: divison result is too small." );
	return true;
}

static bool	printError( std::string msg ) {
	std::cout << "Error: " << msg << std::endl;
	return false;
}
