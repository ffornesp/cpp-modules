/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:00:45 by herz              #+#    #+#             */
/*   Updated: 2024/07/02 18:16:02 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>	// Input output
#include <sstream>	// Stringstream used to process string
#include <climits>	// Limits of int
#include <cfloat>	// Limits of float and double
#include <cstdlib>	// Used for exit


/* Literals

	char			-	Value between ' '

	Base 10 
	Base 8			-	Prefix	0
	Base 16			-	Prefix	0x	||	0X
	Base 2			-	Sufix	0b	||	0B
	
	Long int		-	Sufix	l	||	L
	Unsigned int	-	Sufix	u	||	U
	Long long int	-	Sufix	ll	||	LL
	float			-	Sufix	f
	Bool			-	true		||	false


static void printOutput( std::string type, std::string value ) {
	std::cout << type << " : " << value << std::endl;
}

*/

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

static void stringLiteral( std::string str ) {
	std::cout << "STRING_LITERAL found : " << str << std::endl;

}

static void charLiteral( std::string str ) {
	std::cout << "CHAR_LITERAL found : " << str << std::endl;
	char	c;

//	Convert char to string yay
	if ( str.length() == 3 )
		c = str[1];
	else {
		c = str[2];
		std::cout << "I won't parse this" << std::endl;
	}
	
	if ( isprint(c) )
		std::cout << "Char : " << "\'" << c << "\'" << std::endl;
	else
		std::cout << "Char : Non displayable" << std::endl;
	std::cout << "Int : " << static_cast< int >( c ) << std::endl;
	std::cout << "Float : " << static_cast< float >( c ) << "f" << std::endl;
	std::cout << "Double : " << static_cast< double >( c ) << std::endl;
}

static void	intLiteral( std::string str ) {
	std::cout << "INT_LITERAL found : " << str << std::endl;
}

static void floatLiteral( std::string str ) {
	std::cout << "FLOAT_LITERAL found : " << str << std::endl;
}

static void doubleLiteral( std::string str ) {
	std::cout << "DOUBLE_LITERAL found : " << str << std::endl;
}

/*
static void numberLiteral( long double l ) {
	char	c;
	
	c = static_cast< char >( l );
	if ( l >= 0 && l <= 255 ) {
		if ( isprint(c) )
			std::cout << "Char : " << "\'" << c << "\'" << std::endl;
		else
			std::cout << "Char : Non displayable" << std::endl;
	}
	else
		std::cout << "Char : impossible" << std::endl;
	if ( l < INT_MIN || l > INT_MAX )
		std::cout << "Int : impossible" << std::endl;
	else
		std::cout << "Int : " << static_cast< int >( l ) << std::endl;
	if ( l < FLT_MIN || l > FLT_MAX )
		std::cout << "Float : impossible" << std::endl;
	else
		std::cout << "Float : " << static_cast< float >( l ) << "f" << std::endl;
	if ( l < DBL_MIN || l > DBL_MAX )
		std::cout << "Double : impossible" << std::endl;
	else
		std::cout << "Double : " << static_cast< double >( l ) << std::endl;
}
*/

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

// ToDo : Must detect the type of the literal passed as a parameter, convert it
// from string to it's actual type, then convert it explicitly to the three other
// data types.

void ScalarConverter::convert( std::string str ) {
	unsigned int		input;

	std::cout << "Input received : " << str << std::endl;

	input = checkInput(str);
	switch ( input ) {
		case INVALID : 
			std::cerr << "Input is invalid, please run program with one C++ literal in it\'s most common form." << std::endl;
			if ( str.length() == 1 )
				std::cerr << "\tUsage: ./convert \\\'c\\\'" << std::endl;
			exit( 1 );
		case STRING_LITERAL :
			stringLiteral(str);
			break ;
		case CHAR_LITERAL :
			charLiteral(str);
			break ;
		case INT_LITERAL :
			intLiteral(str);
			break ;
		case FLOAT_LITERAL :
			floatLiteral(str);
			break ;
		case DOUBLE_LITERAL :
			doubleLiteral(str);
			break ;
	}
}
