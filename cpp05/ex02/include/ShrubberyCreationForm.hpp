/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:07:02 by ffornes-          #+#    #+#             */
/*   Updated: 2024/06/10 15:08:32 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm {
	private:
	public:
		ShrubberyCreationForm( std::string target );
		~ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm& old );
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& );
}
