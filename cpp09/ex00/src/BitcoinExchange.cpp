/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:25:43 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/24 15:51:46 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

#include <iostream>

BitcoinExchange::InvalidReadException::InvalidReadException( const std::string& msg ) : std::invalid_argument( "Unable to read " + msg ) {}

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
		data = readFile( "./data.csv", ',' );
		file = readFile( filename, '|' );
	}
	catch ( BitcoinExchange::InvalidReadException& e ) {
		std::cerr << e.what() << std::endl;
		return ;
	}
}

std::map< std::string, float >	BitcoinExchange::readFile( const char *filename, char c ) {
	std::map< std::string, float >	data;
	std::ifstream	file( filename );

	if ( !file )
		throw BitcoinExchange::InvalidReadException( filename ); 

	std::string	line;
	while ( std::getline( file, line ) ) {
		std::string			date;
		float				value;
		std::istringstream	ss( line );

		std::getline( ss , date, c );
		if ( ss >> value ) {
			data[date] = value;
			std::cout << "Date: " << date << " Value: " << value << std::endl;
		}
		else {
			std::cerr << "Failed to parse date from line: " << line << std::endl;
		}
	}
	return data;
}
