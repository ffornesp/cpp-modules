/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:30:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/07/02 14:39:32 by ffornes-         ###   ########.fr       */
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
# ifndef NUMBER_LITERAL
#  define NUMBER_LITERAL 3
# endif

class	ScalarConverter {
	private :

	public :
		static void convert( std::string ) ;		
};
