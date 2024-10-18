/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:49:48 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/18 17:15:14 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <set>

class Span {
	private:
		unsigned int 			_size;
		std::multiset< int >	_content;
	public:
		Span( void );
		Span( unsigned int size );
		~Span( void );
		Span( const Span& s );
		Span&	operator=( const Span& copy );

		void			addNumber( int n );
		unsigned long	shortestSpan( void );
		unsigned long	longestSpan( void );
};
