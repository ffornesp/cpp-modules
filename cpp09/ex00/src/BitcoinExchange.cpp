/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:25:43 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/24 15:25:39 by ffornes-         ###   ########.fr       */
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

std::map< std::string, float >	BitcoinExchange::readDatabase( void ) {
	std::map< std::string, float >	data;
	std::ifstream	file( "./data.csv" );

	if ( !file )
		throw BitcoinExchange::InvalidReadException( "data.csv" ); 

	std::string	line;
	while ( std::getline( file, line ) ) {
		std::string			date;
		float				value;
		std::istringstream	ss( line );

		std::getline( ss , date, ',' );
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
