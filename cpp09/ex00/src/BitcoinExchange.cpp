/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:25:43 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/24 17:11:48 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

#include <cctype>

#include <iostream>

BitcoinExchange::BitcoinExchange( void ) {}

BitcoinExchange::~BitcoinExchange( void ) {}

// FIX COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR
BitcoinExchange::BitcoinExchange( const BitcoinExchange& old ) {
	*this = old;
}
BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& copy ) {
	( void )copy;
	return *this;
}
// ENDFIX

void	BitcoinExchange::btc( const char *filename ) {
	std::map< std::string, float > data;
	std::map< std::string, float > file;

	try {
		data = readFile( "./data.csv" );
		file = readFile( filename );
	}
	catch ( std::runtime_error& e ) {
		std::cerr << e.what() << std::endl;
		return ;
	}
}

std::map< std::string, float >	BitcoinExchange::readFile( const char *filename ) {
	std::map< std::string, float >	data;
	std::ifstream	file( filename );

	if ( !file )
		throw std::runtime_error( "Unable to read " + static_cast< std::string >( filename ) );

	std::string	line;
	char		c;

	c = detectDelimiter( filename );
	if ( !c ) 
		throw std::runtime_error( "No delimiter found in " + static_cast< std::string >( filename ) );
	while ( std::getline( file, line ) ) {
		std::string			date;
		float				value;
		std::istringstream	ss( removeSpace( line ) );

		std::getline( ss , date, c );
		if ( ss >> value ) {
			data[date] = value;
			std::cout << "Date: " << date << " Value: " << value << std::endl;
		}
		else if ( date != "date" && date != "date " )
			throw std::runtime_error( "Invalid format in line: " + line );
	}
	file.close();
	return data;
}

// Detects 
char	BitcoinExchange::detectDelimiter( const char *filename ) {
	std::ifstream	file( filename );

	std::string	header;
	if ( std::getline( file, header ) ) {
		if ( header.find( ',' ) != std::string::npos )
			return ',';
		else if ( header.find( '|' ) != std::string::npos )
			return '|';
	}
	return '\0';
}

// Removes spaces from line which makes it easier to print everything with the same
//	identation. Also prevents errors when header contains spaces.
std::string	BitcoinExchange::removeSpace( const std::string& line ) {
    std::string result;

	result.reserve( line.size() - 2 );
	for ( std::string::const_iterator it = line.begin(); it != line.end(); ++it )
		if ( !std::isspace( static_cast< unsigned char >( *it ) ) )
			result += *it;
    return result;
}
