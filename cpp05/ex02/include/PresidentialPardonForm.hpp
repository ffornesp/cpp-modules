/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:58:05 by ffornes-          #+#    #+#             */
/*   Updated: 2024/06/10 15:04:12 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm {
	private:
	public:
		PresidentialPardonForm( std::string target );
		~PresidentialPardonForm( void );
		PresidentalPardonForm( const PresidentialPardonForm& old );
		PresidentialPardonForm& operator=( const PresidentialPardonForm& );
}
