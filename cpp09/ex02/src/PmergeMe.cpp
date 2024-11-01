/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:11 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/31 18:17:30 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <deque>
#include <list>

ChainLink::ChainLink( void ) : _first( 0 ), _second( 0 ) {}

ChainLink::ChainLink( int& i, int& j ) : _first( i ), _second( j ) {}

ChainLink::~ChainLink( void ) {}

ChainLink::ChainLink( const ChainLink& old ) : _first( old._first ), _second( old._second) {}

ChainLink&	ChainLink::operator=( const ChainLink& copy ) {
	if ( this != &copy ) {
		this->_first = copy._first;
		this->_second = copy._second;
	}
	return *this;
}

int	ChainLink::getFirst( void ) const {
	return this->_first;
}

int	ChainLink::getSecond( void ) const {
	return this->_second;
}

void	ChainLink::setFirst( int n ) {
	this->_first = n;
}

void	ChainLink::setSecond( int n ) {
	this->_second = n;
}

bool	ChainLink::compareElements( void ) const {
	return this->_first > this->_second;
}

bool	ChainLink::compareFirst( const ChainLink link ) const {
	return this->getFirst() > link.getFirst();
}

void	ChainLink::swapElements( void ) {
	int	n;

	n = this->getFirst();
	this->setFirst( this->getSecond( ) );
	this->setSecond( n );
}

std::ostream&	operator<<( std::ostream& os, const ChainLink& link ) {
	os << link.getFirst() << " " << link.getSecond();
	return os;
}
