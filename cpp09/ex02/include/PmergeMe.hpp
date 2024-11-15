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

void	checkInput( char *argv[] );

void	mergeInsertionSort( std::deque< int >& );

template< typename T >
void	printContent( T& t ) {
	for ( typename T::iterator it = t.begin(); it != t.end(); it++ )
		std::cout << *it << " ";
	std::cout << std::endl;
}

/*
		WHAT TO DO?

	call merge-insertion-sort
		element_size = 1
		size = 9

	5 2 3 1 4 7 6 9 8 

	swap content inside pairs

	[5-2] [3-1] [4-7] [6-9] | 8				
	[2-5] [1-3] [4-7] [6-9] | 8

	call merge-insertion-sort
		element_size = 2
		size = 4

	swap content inside pairs

	[(2-5) (1-3)] [(4-7) (6-9)]
	[(1-3)-(2-5)] [(4-7)-(6-9)]

	call merge-insertion-sort
		element_size = 4
		size = 2

	swap content inside pairs

	[((1-3)-(2-5)) ((4-7)-(6-9))] 		since 5 < 9 we do not swap content
	[((1-3)-(2-5))-((4-7)-(6-9))] 

	call merge-insertion-sort
		element_size = 8
		size = 1 ; then return

	
	call jacobsthal haha xdxd

	when calling jacobsthal we will keep the reference of the paired number using an iterator
	the main difference between deque and list is that list will be able to keep it's iterator
	intact event tho we insert stuff in between, however that's not the case for deque

*/
