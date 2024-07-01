/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:00:45 by herz              #+#    #+#             */
/*   Updated: 2024/07/01 14:04:41 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <climits>

void ScalarConverter::convert( std::string str ) {
	char	c = 0;
	int		i = 0;
	float	f = 0;
	double	d = 0;
	std::stringstream ss;

	ss << str;
	ss >> d;
	f = d;
	i = d;
	c = i;

	std::cout << "Char : ";
	if ( i >= 0 && i <= 255 ) {
		if ( isprint(c) )
			std::cout << "\'" << c << "\'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;

	std::cout << "Int : ";
	if ( d < INT_MIN || d > INT_MAX )
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;

	std::cout << "Float : " << f << std::endl;
	std::cout << "Double : " << d << std::endl;
}
