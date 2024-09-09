/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:31:43 by ffornes-          #+#    #+#             */
/*   Updated: 2024/09/09 16:24:38 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class	Base {
	public :
		virtual ~Base( void ) {};
};

class	A : public Base {};

class	B : public Base {};

class	C : public Base {};
