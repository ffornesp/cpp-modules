/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:07:02 by ffornes-          #+#    #+#             */
/*   Updated: 2024/06/11 15:47:25 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class	ShrubberyCreationForm : public AForm {
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm( std::string target );
		~ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm& old );
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& );
	
		virtual void	action( void ) const ;
};
