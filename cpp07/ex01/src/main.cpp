/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:39:29 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/08 16:20:44 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iter.hpp>

int	main( void ) {
	int	i[5] = { 0, 1, 2, 3, 4 };
	test1( i, 5 );
	float	f[2] = { 0.5f, -25.42f };
	test1( f, 2 );
	return 0;
}
