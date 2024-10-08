/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:59:40 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/08 15:10:33 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template< typename T >
void		swap( T & x, T & y ) {
	T	t;

	t = x;
	x = y;
	y = t;
}

template< typename T >
T const &	max( T const & x, T const & y ) {
	return ( x > y ? x : y );
}

template< typename T >
T const &	min( T const & x, T const & y ) {
	return ( x < y ? x : y );
}
