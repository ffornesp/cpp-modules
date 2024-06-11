/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:04:42 by ffornes-          #+#    #+#             */
/*   Updated: 2024/06/11 15:11:09 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class	RobotomyRequestForm : public AForm {
	private:
		std::string	_target;
	public:
		RobotomyRequestForm( std::string target );
		~RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm& old );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& );

		virtual void	action( void ) const ;
};
