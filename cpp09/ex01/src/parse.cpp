/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:29:30 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/26 16:19:25 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <iostream>

static bool	inputError( std::string msg );
static bool	isOperator( char c );

bool	validateInput( const std::string str ) {
	bool	isNumber = true;
	size_t	digitCount = 0;
	size_t	operatorCount = 0;

	for ( size_t i = 0; i < str.size(); i++ ) {
		if ( isdigit( str[ i ] ) && isNumber ) {
			digitCount++;
			if ( i > 0 )
				isNumber = false;
		}
		else if ( isOperator( str[ i ] ) && !isNumber ) {
			operatorCount++;
			isNumber = true;
		}
		else if ( !isdigit( str[ i ] ) && !isOperator( str[ i ] ) )
			return inputError( "Please enter digits and operators \" + - / * \" only." );
	}
	if ( operatorCount != digitCount - 1 || !operatorCount )
		return inputError( "wrong amount of operators." );
	return true;
}

std::string	removeSpaces( const std::string& str ) {
	std::string	result;

	for ( size_t i = 0; i < str.size(); i++ ) {
		if ( !isspace( str[ i ] ) )
			result += str[ i ];
	}
	return result;
}

static bool	inputError( std::string msg ) {
	std::cout << "Error: " << msg << std::endl;
	return false;
}

static bool	isOperator( char c ) {
	if ( c != '+' && c != '-' && c != '/' && c != '*' )
		return false;
	return true;
}


