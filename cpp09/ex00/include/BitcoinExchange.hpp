/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:25:58 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/24 15:50:42 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <stdexcept>

class BitcoinExchange {
	private:

	public:
		BitcoinExchange( void );
		~BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange& );
		BitcoinExchange& operator=( const BitcoinExchange& );
	
		void	btc( const char* );
		std::map< std::string, float > readFile( const char*, char );

	class	InvalidReadException : public std::invalid_argument {
		public:
			InvalidReadException( const std::string& msg );
	};
};
