/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:13:19 by herz              #+#    #+#             */
/*   Updated: 2024/03/26 14:18:37 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class	Form {
	private:
		const std::string	_name;
		bool				_sign;
		const unsigned int	_signGrade;
		const unsigned int	_executeGrade;
	public:
		Form( void );
		~Form( void );
		Form( const Form& );
		Form& operator=( const Form& );

		std::string		getName( void ) const;
		bool			getSign( void ) const;
		unsigned int	getSignGrade( void ) const;
		unsigned int	getExecuteGrade( void ) const;

	class	GradeTooLowException : public std::exception {
		public:
			virtual const char*	what() const throw() {
				return ("Grade is too low");
			}
	};

	class	GradeTooHighException : public std::exception {
		public:
			virtual const char*	what() const throw() {
				return ("Grade is too high");
			}
	};
};
