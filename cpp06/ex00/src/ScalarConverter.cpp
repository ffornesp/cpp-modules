/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:00:45 by herz              #+#    #+#             */
/*   Updated: 2024/07/03 13:46:59 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>	// Input output
#include <sstream>	// Stringstream used to process string
#include <climits>	// Limits of int
#include <cfloat>	// Limits of float and double
#include <cstdlib>	// Used for exit

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

// ------------------------------------------------------------------------------- //

static int	checkInput( std::string str ) {
	unsigned int	charCount = 0;
	unsigned int	signCount = 0;
	unsigned int	dotCount = 0;

	if ( str.length() == 1 && !isdigit(str[0]) )
		return INVALID;
	if ( str == "-inff" || str == "+inff" || str == "-inf" || str == "+inf" )
		return STRING_LITERAL;
	else if ( str == "nan" || str == "true" || str == "false" )
		return STRING_LITERAL;
	if ( *str.begin() == '\'' && ( str.length() == 3 || str.length() == 4 )) {
		if ( *(--str.end()) != '\'' )
			return INVALID;
		else if ( str.length() == 4 && str[1] != '\\' )
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
				return FLOAT_LITERAL;
		}
	}
	if ( dotCount == 1 && charCount == 0 )
		return DOUBLE_LITERAL;
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
	if ( l > 255 || l < 0 )
		std::cout << "impossible" << std::endl;
	else if ( !isprint(info->c) )
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << info->c << std::endl;
	
	std::cout << "Int : ";
	if ( l > INT_MAX || l < INT_MIN )
		std::cout << "impossible" << std::endl;
	else
		std::cout << info->i << std::endl;
	
	std::cout << "Float : ";
	if ( l > FLT_MAX || l < FLT_MIN )
		std::cout << "impossible" << std::endl;
	else
		std::cout << info->f << "f" << std::endl;

	std::cout << "Double : ";
	if ( l > DBL_MAX || l < DBL_MIN )
		std::cout << "impossible" << std::endl;
	else
		std::cout << info->d << std::endl;
}

static void stringLiteral( std::string str ) {	// ToDo
	std::cout << "STRING_LITERAL found : " << str << std::endl;
}

// ToDo : Must detect the type of the literal passed as a parameter, convert it
// from string to it's actual type, then convert it explicitly to the three other
// data types.

void ScalarConverter::convert( std::string str ) {
	unsigned int		input;
	std::stringstream	ss;
	t_info				info;

	input = checkInput(str);
	if ( input != INVALID && input != STRING_LITERAL )
		ss << str;
	switch ( input ) {
		case INVALID : 
			std::cerr << "Input is invalid, please run program with one C++ literal" << \
			"in it\'s most common form." << std::endl;
			if ( str.length() == 1 )
				std::cerr << "\tUsage: ./convert \\\'c\\\'" << std::endl;
			exit( 1 );
		case STRING_LITERAL :
			stringLiteral(str); // TO IMPLEMENT
			break ;
		case CHAR_LITERAL :
			if ( str.length() == 3 )
				info.c = str[1];
			else {
				info.c = str[2];
				std::cout << "I won't parse this" << std::endl; // ToDo
			}
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
		case FLOAT_LITERAL :
			ss >> info.f;
			info.c = static_cast< char >( info.f );
			info.i = static_cast< int >( info.f );
			info.d = static_cast< double >( info.f );
			printInfo( &info, str, false );
			break ;
		case DOUBLE_LITERAL :
			ss >> info.d;
			info.c = static_cast< char >( info.d );
			info.i = static_cast< int >( info.d );
			info.f = static_cast< float >( info.d );
			printInfo( &info, str, false );
			break ;
	}
}
