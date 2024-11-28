/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:29:41 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/28 19:00:14 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <limits>
#include <cfloat>

std::string	removeSpaces( const std::string& );
bool		validateInput( const std::string str );

void	RPN( const std::string );
bool	calculate( long double& n1, long double n2, char operation );
