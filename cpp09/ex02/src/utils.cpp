/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:36:18 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/20 12:37:21 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printInfo( std::deque< int > src, std::deque< int > mainChain, size_t groupSize ) {
	std::cout << std::endl << "Main chain:\t";
	printGroups( mainChain, groupSize );
	std::cout << "Original:\t";
	printGroups( src, groupSize );
	std::cout << std::endl;
}
