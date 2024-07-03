/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:00:45 by herz              #+#    #+#             */
/*   Updated: 2024/07/03 16:43:53 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>	// Input output
#include <sstream>	// Stringstream used to process string
#include <climits>	// Limits of int
#include <cfloat>	// Limits of float and double
#include <cstdlib>	// Used for exit

#include <limits>

ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::~ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( const ScalarConverter& copy )
{
	( void )copy;
}

ScalarConverter&	ScalarConverter::operator=( const ScalarConverter& copy )
{
	( void )copy;
	return ( *this );
}

/* ************************************************************************** */

static int	checkInput( std::string str ) {
	unsigned int	charCount = 0;
	unsigned int	signCount = 0;
	unsigned int	dotCount = 0;

	if ( str.length() == 1 && !isdigit(str[0]) )
		return INVALID;
	if ( str == "-inff" || str == "+inff" || str == "nanf" )
		return FLT_PSEUDOL;
	else if ( str == "-inf" || str == "+inf" || str == "nan" )
		return DBL_PSEUDOL;
	if ( *str.begin() == '\'' && str.length() == 3 ) {
		if ( *(--str.end()) != '\'' )
			return INVALID;
		else 
			return CHAR_LITERAL;
	}
	for ( std::string::iterator it=str.begin(); it!=str.end(); ++it ) {
		if ( !isalpha(*it) ) {
			if ( *it == '.' )
				dotCount++;
			else if ( *it == '-' || *it == '+' )
				signCount++;
			else if ( !isdigit(*it) && *it != '\\' )
				return INVALID;
			if ( dotCount > 1 || signCount > 1 )
				return INVALID;
		}
		else {
			if ( *it != 'l' && *it != 'L' && *it != 'u' && *it != 'U' && *it != 'f' )
				return INVALID;
			charCount++;
			if ( charCount > 1 && ( *it != 'l' && *it != 'L' ))
				return INVALID;
			else if ( charCount == 1 && *it == 'f' && *(it + 1) == '\0' )
				return FLT_LITERAL;
		}
	}
	if ( dotCount == 1 && charCount == 0 )
		return DBL_LITERAL;
	return INT_LITERAL;
}

static void printInfo( t_info *info, std::string str, bool flag ) {
	std::stringstream	ss;
	long double			l;

	ss << str;
	ss >> l;
	if ( flag )
		l = static_cast< long double >( info->c );
	
	std::cout << "Char : ";
	if ( l < std::numeric_limits< char >::min() || l > std::numeric_limits< char >::max() )
		std::cout << "impossible" << std::endl;
	else if ( !isprint(info->c) )
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << info->c << "\'" << std::endl;
	
	std::cout << "Int : ";
	if ( l < std::numeric_limits< int >::min() || l > std::numeric_limits< int >::max() )
		std::cout << "impossible" << std::endl;
	else
		std::cout << info->i << std::endl;
	
	std::cout << "Float : ";
	if ( l < - std::numeric_limits< float >::max() || l > std::numeric_limits< float >::max() )
		std::cout << "impossible" << std::endl;
	else
		std::cout << info->f << ".0f" << std::endl;

	std::cout << "Double : ";
	if ( l < - std::numeric_limits< double >::max() || l > std::numeric_limits< double >::max() )
		std::cout << "impossible" << std::endl;
	else
		std::cout << info->d << ".0" << std::endl;
}

static void stringLiteral( std::string str, unsigned int type ) {
	int		ptype = 0;
	t_info	info;

	std::cout << "Char : impossible" << std::endl;
	std::cout << "Int : impossible" << std::endl;
	if ( str == "nan" )
		ptype = NAN;
	else if ( str == "+inf" )
		ptype = INF;
	else if ( str == "-inf" )
		ptype = NINF;
	switch ( type ) {
		case FLT_PSEUDOL :
			info.f = std::numeric_limits< float >::infinity();
			if ( ptype == NINF )
				info.f *= -1;
			else if ( ptype == NAN )
				info.f = std::numeric_limits< float >::signaling_NaN();
			info.c = static_cast< char >( info.f );
			info.i = static_cast< int >( info.f );
			info.d = static_cast< double >( info.f );
			break ;
		case DBL_PSEUDOL :
			info.d = std::numeric_limits< double >::infinity();
			if ( ptype == NINF )
				info.d *= -1;
			else if ( ptype == NAN )
				info.d = std::numeric_limits< double >::signaling_NaN();
			info.c = static_cast< char >( info.d );
			info.i = static_cast< int >( info.d );
			info.f = static_cast< float >( info.d );		
			break ;
	}
	std::cout << "Float : " << info.f << "f" << std::endl;
	std::cout << "Double : " << info.d << std::endl;
}

void ScalarConverter::convert( std::string str ) {
	unsigned int		input;
	std::stringstream	ss;
	t_info				info;

	input = checkInput(str);
	if ( input != INVALID && input != FLT_PSEUDOL && input != DBL_PSEUDOL )
		ss << str;
	switch ( input ) {
		case INVALID : 
			std::cerr << "Input is invalid, please run program with one C++ literal " << \
			"in it\'s most common form." << std::endl << \
			"To input chars that include \'\\\' export them as evals." << std::endl \
			<< "\tUsage: ./convert \\\'c\\\' || export A=\'\\0\' && ./convert $A" \
			<< std::endl;
			exit( 1 );
		case CHAR_LITERAL :
			if ( str.length() == 3 )
				info.c = str[1];
			info.i = static_cast< int >( info.c );
			info.f = static_cast< float >( info.c );
			info.d = static_cast< double >( info.c );
			printInfo( &info, str, true );
			break ;
		case INT_LITERAL :
			ss >> info.i;
			info.c = static_cast< char >( info.i );
			info.f = static_cast< float >( info.i );
			info.d = static_cast< double >( info.i );
			printInfo( &info, str, false );
			break ;
		case FLT_LITERAL :
			ss >> info.f;
			info.c = static_cast< char >( info.f );
			info.i = static_cast< int >( info.f );
			info.d = static_cast< double >( info.f );
			printInfo( &info, str, false );
			break ;
		case FLT_PSEUDOL :
			str.erase( str.end() - 1, str.end() );
			stringLiteral( str, input );
			break ;
		case DBL_LITERAL :
			ss >> info.d;
			info.c = static_cast< char >( info.d );
			info.i = static_cast< int >( info.d );
			info.f = static_cast< float >( info.d );
			printInfo( &info, str, false );
			break ;
		case DBL_PSEUDOL :
			stringLiteral( str, input );
			break ;
	}
}
