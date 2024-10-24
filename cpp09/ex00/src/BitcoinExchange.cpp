/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:25:43 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/24 17:48:04 by ffornes-         ###   ########.fr       */
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
		data = readFile( "data.csv" );
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
	std::string		sfilename;

	sfilename = static_cast< std::string >( filename );
	if ( !file )
		throw std::runtime_error( "Unable to read " + sfilename );

	std::string	line;
	char		c;

	c = detectDelimiter( filename );
	if ( !c )
		throw std::runtime_error( "Invalid format, no delimiter in " + sfilename );
	else if ( c != '|' && sfilename != "data.csv" )
		throw std::runtime_error( "Invalid format, wrong delimiter in " + sfilename );
	while ( std::getline( file, line ) ) {
		std::string			date;
		float				value;
		std::istringstream	ss( removeSpace( line ) );

		std::getline( ss , date, c );
		if ( ss >> value ) {
			data[date] = value;
			std::cout << "Date: " << date << " Value: " << value << std::endl;
		}
		else if ( date != "date" )
			throw std::runtime_error( "Invalid format in " + sfilename + ", in line: " + line );
		else
			ss.clear();
	}
	file.close();
	return data;
}

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
