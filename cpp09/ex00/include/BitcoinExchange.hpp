/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:25:58 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/30 15:47:26 by ffornes-         ###   ########.fr       */
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
		std::multimap< std::string, float > readFile( std::string );
		void	processFile( std::multimap< std::string, float >, std::multimap< std::string, float > );

		char		detectDelimiter( std::string& );
		std::string	removeSpace( const std::string& );
		bool		validateDate( const std::string& );
};
