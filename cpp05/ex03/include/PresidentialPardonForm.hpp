/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:58:05 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/09 17:17:01 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm {
	private:
		std::string	_target;
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		~PresidentialPardonForm( void );
		PresidentialPardonForm( const PresidentialPardonForm& old );
		PresidentialPardonForm& operator=( const PresidentialPardonForm& );

		virtual void	action( void ) const ;
};
