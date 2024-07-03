/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:30:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/07/03 15:59:51 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

# define INVALID 0
# define CHAR_LITERAL 1 
# define INT_LITERAL 2
# define FLT_LITERAL 3
# define DBL_LITERAL 4
# define FLT_PSEUDOL 5
# define DBL_PSEUDOL 6

# define NAN 0
# define INF 1
# define NINF 2

typedef struct	s_info
{
	char	c;
	int		i;
	float	f;
	double	d;
}	t_info;

class	ScalarConverter {
	private :
		ScalarConverter( void );
		~ScalarConverter( void );
		ScalarConverter( const ScalarConverter& copy );
		ScalarConverter&	operator=( const ScalarConverter& copy );
	public :
		static void convert( std::string ) ;		
};
