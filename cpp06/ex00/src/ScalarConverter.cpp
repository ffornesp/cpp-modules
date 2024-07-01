/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:00:45 by herz              #+#    #+#             */
/*   Updated: 2024/07/01 17:48:25 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <climits>
#include <cfloat>

static void StringLiterals( std::string str ) {
	std::cout << "StringLiterals called with string : " << str << std::endl;
}

static void RegularNumbers( long double l ) {
	char	c;
	int		i;
	float	f;
	double	d;

	d = l;
	f = l;
	i = l;
	c = l;
	if ( l >= 0 && l <= 255 ) {
		if ( isprint(c) )
			std::cout << "Char : " << "\'" << c << "\'" << std::endl;
		else
			std::cout << "Char : Non displayable" << std::endl;
	}
	else
		std::cout << "Char : impossible" << std::endl;

	if ( l < INT_MIN || l > INT_MAX )
		std::cout << "Int : impossible" << std::endl;
	else
		std::cout << "Int : " << i << std::endl;

	if ( l == 0 )
		std::cout << "Float : 0f" << std::endl;
	else if ( l < FLT_MIN || l > FLT_MAX )
		std::cout << "Float : impossible" << std::endl;
	else
		std::cout << "Float : " << f << "f" << std::endl;

	if ( l == 0 )
		std::cout << "Double : 0f" << std::endl;
	else if ( l < DBL_MIN || l > DBL_MAX )
		std::cout << "Double : impossible" << std::endl;
	else
		std::cout << "Double : " << d << "f" << std::endl;

}

void ScalarConverter::convert( std::string str ) {
	long double	l = 0;
	std::stringstream ss;
	bool		flag = false;

	ss << str;
	ss >> l;
	if ( l == 0 ) {
		for ( std::string::iterator it=str.begin(); it!=str.end(); ++it ) {
			if ( *it != '0' ) {
				flag = true;
				break ;
			}
		}
		if ( flag )
			StringLiterals(str);
		else
			RegularNumbers(0);
	}
	else
		RegularNumbers(l);
}
