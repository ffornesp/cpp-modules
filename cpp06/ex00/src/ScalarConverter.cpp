/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:00:45 by herz              #+#    #+#             */
/*   Updated: 2024/07/02 17:01:22 by ffornes-         ###   ########.fr       */
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

static int	validateInput( std::string str ) {
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
		}
		else {
			if ( *it != 'l' && *it != 'L' && *it != 'u' && *it != 'U' && *it != 'f' )
				return INVALID;
			charCount++;
			if ( charCount > 1 && ( *it != 'l' && *it != 'L' ))
				return INVALID;
		}
	}

	if ( dotCount > 1 || signCount > 1 )
		return INVALID;
	return NUMBER_LITERAL;
}

static void stringLiteral( std::string str ) {
	std::cout << "STRING_LITERAL found : " << str << std::endl;

}

static void charLiteral( std::string str ) {
	std::cout << "CHAR_LITERAL found : " << str << std::endl;
//	char	c;

//	c = str;
//	std::cout << "Char : " << c << std::endl;
}

static void numberLiteral( long double l ) {
	char	c;
	int		i;
	float	f;
	double	d;

	d = static_cast< double >( l );
	f = static_cast< float >( l );
	i = static_cast< int >( l );
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
		std::cout << "Int : " << i << std::endl;

	if ( l == 0 )
		std::cout << "Float : 0f" << std::endl;
	else if ( l < FLT_MIN || l > FLT_MAX )
		std::cout << "Float : impossible" << std::endl;
	else
		std::cout << "Float : " << f << "f" << std::endl;

	if ( l == 0 )
		std::cout << "Double : 0" << std::endl;
	else if ( l < DBL_MIN || l > DBL_MAX )
		std::cout << "Double : impossible" << std::endl;
	else
		std::cout << "Double : " << d << std::endl;

}

void ScalarConverter::convert( std::string str ) {
	long double			l = 0;
	std::stringstream	ss;
	unsigned int		input;

	std::cout << "Input received : " << str << std::endl;

	input = validateInput(str);
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
		case NUMBER_LITERAL :
			ss << str;
			ss >> l;
			numberLiteral(l);
			break ;
	}
}
