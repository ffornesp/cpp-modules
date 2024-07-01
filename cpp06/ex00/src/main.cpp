/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:31:47 by ffornes-          #+#    #+#             */
/*   Updated: 2024/07/01 17:34:30 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main( void ) {
	ScalarConverter::convert("0000");
	ScalarConverter::convert("1249.152f");
	ScalarConverter::convert("-inff");
	ScalarConverter::convert("inff");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("inf");
	ScalarConverter::convert("nan");
	return ( 0 );
}
