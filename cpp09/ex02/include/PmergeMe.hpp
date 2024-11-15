/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:07:53 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/14 18:49:41 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <deque>
#include <cstdlib>
#include <iostream>

#ifndef INCREMENT
# define INCREMENT	0
#endif
#ifndef DECREMENT
# define DECREMENT	1
#endif

void	mergeInsertionSort( std::deque< int >& );

template< typename T >
void	printContent( T& t ) {
	for ( typename T::iterator it = t.begin(); it != t.end(); it++ )
		std::cout << *it << " ";
	std::cout << std::endl;
}
