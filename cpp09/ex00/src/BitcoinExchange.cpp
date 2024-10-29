/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:25:43 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/29 19:00:57 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

#include <cctype>

#include <iostream>
#include <cstdlib>

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
		processFile( data, file );
	}
	catch ( std::runtime_error& e ) {
		std::cerr << e.what() << std::endl;
	}
	catch ( std::bad_alloc& e ) {
		std::cerr << "Not enough memory" << std::endl;
	}
	return ;
}

std::map< std::string, float >	BitcoinExchange::readFile( std::string filename ) {
	std::map< std::string, float >	data;
	std::ifstream	file( filename.c_str() );

	if ( !file )
		throw std::runtime_error( "Unable to read " + filename );
	
	std::string	line;
	char		c;

	c = detectDelimiter( filename );
	if ( !c )
		throw std::runtime_error( "Invalid format, no delimiter in " + filename );
	else if ( c != '|' && filename != "data.csv" )
		throw std::runtime_error( "Invalid format, wrong delimiter in " + filename );
	while ( std::getline( file, line ) ) {
		std::string			date;
		float				value;
		std::istringstream	ss( removeSpace( line ) );

		std::getline( ss , date, c );
		if ( ss >> value )
			data[date] = value;
		else if ( date != "date" )
			throw std::runtime_error( "Invalid format in " + filename + ", in line: " + line );
		else
			ss.clear();
	}
	file.close();
	return data;
}

char	BitcoinExchange::detectDelimiter( std::string& filename ) {
	std::ifstream	file( filename.c_str() );

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

void	BitcoinExchange::processFile( std::map< std::string, float > data, std::map< std::string, float > file ) {
	for ( std::map< std::string, float >::iterator it = file.begin(); it != file.end(); ++it ) {
		if ( validateDate( it->first ) ) {
			std::cout << it->first << " is a valid date" << std::endl;
			// ToDo::: Handle output
		}
	}
	( void )data;
}

static bool	badInput( const std::string& str ) {
	std::cerr << "Error: Bad input => " + str << std::endl;
	return false;
}

bool	BitcoinExchange::validateDate( const std::string& str ) {
	int					date[3];
	std::stringstream	ss( str );
	std::string			aux;
	
	int	i = 0;
	while ( getline( ss, aux, '-' ) && i < 3 )
		date[i++] = atoi( aux.c_str() );

// Check the year and month are valid values
	if ( date[0] < 2009 || date[1] > 12 )
		return badInput( str );
// Check limit case for data.csv
	if ( date[0] == 2009 && date[1] == 1 && date[2] < 2 )
		return badInput( str );
// Check the day is a valid input
	switch ( date[1] ) {
		case 2:
			if ( date[2] > 29 )
				return badInput( str );
			if ( date[2] > 28 ) {
				if ( date[0] % 4 != 0 )
					return badInput( str );
				else if ( date[0] % 100 == 0 && date[0] % 400 != 0 )
					return badInput( str );
			}
			break ;
		case 4:
		case 6:
		case 9:
		case 11:
			if ( date[2] > 30 ) {
				return badInput( str );
			}
			break ;
		default:
			if ( date[2] > 31 )
				return badInput( str );
			break ;
	}
	return true;
}
