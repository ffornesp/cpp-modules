/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:04:42 by ffornes-          #+#    #+#             */
/*   Updated: 2024/06/10 15:06:58 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class	RobotomyRequestForm : public AForm {
	private:
	public:
		RobotomyRequestForm( std::string target );
		~RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm& old );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& );
}
