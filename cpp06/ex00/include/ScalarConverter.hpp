/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:30:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/07/02 18:13:52 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

# ifndef INVALID
#  define INVALID 0
# endif
# ifndef STRING_LITERAL
#  define STRING_LITERAL 1
# endif
# ifndef CHAR_LITERAL
#  define CHAR_LITERAL 2
# endif
# ifndef INT_LITERAL
#  define INT_LITERAL 3
# endif
# ifndef FLOAT_LITERAL
#  define FLOAT_LITERAL 4
# endif
# ifndef DOUBLE_LITERAL
#  define DOUBLE_LITERAL 5
# endif

class	ScalarConverter {
	private :
		ScalarConverter( void );
		~ScalarConverter( void );
		ScalarConverter( const ScalarConverter& copy );
		ScalarConverter&	operator=( const ScalarConverter& copy );
	public :
		static void convert( std::string ) ;		
};
