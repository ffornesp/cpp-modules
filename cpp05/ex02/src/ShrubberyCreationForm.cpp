/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:55:46 by ffornes-          #+#    #+#             */
/*   Updated: 2024/06/11 16:21:51 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& old ) : AForm("ShrubberyCreationForm", 145, 137) {
	*this = old;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& old ) {
	if ( this != &old ) {
		this->AForm::_sign = old.AForm::_sign;
		this->_target = old._target;
	}
	return ( *this );
}

void	ShrubberyCreationForm::action( void ) const {
	std::string		filename = this->_target + "_shrubbery";
	std::ofstream	outfile;

	outfile.open(filename.c_str());
	if ( outfile.fail() )
		std::cerr << "Error trying to open file '" << filename << "'" << std::endl;
	else {
		outfile << "         . . .\n       .        .  .     ..    .\n    .                 .         .  .\n                    .\n                   .                ..\n   .          .            .              .\n   .            '.,        .               .\n   .              'b      *\n    .              '$    #.                ..\n   .    .           $:   #:               .\n ..      .  ..      *#  @):        .   . .\n              .     :@,@):   ,.**:'   .\n  .      .,         :@@*: ..**'      .   .\n           '#o.    .:(@'.@*'  .\n   .  .       'bq,..:,@@*'   ,*      .  .\n              ,p$q8,:@)'  .p*'      .\n       .     '  . '@@Pp@@*'    .  .\n        .  . ..    Y7'.'     .  .\n                  :@):.\n                 .:@:'.\n               .::(@:.      -Sam Blumenstien-" << std::endl;
		outfile << "         . . .\n       .        .  .     ..    .\n    .                 .         .  .\n                    .\n                   .                ..\n   .          .            .              .\n   .            '.,        .               .\n   .              'b      *\n    .              '$    #.                ..\n   .    .           $:   #:               .\n ..      .  ..      *#  @):        .   . .\n              .     :@,@):   ,.**:'   .\n  .      .,         :@@*: ..**'      .   .\n           '#o.    .:(@'.@*'  .\n   .  .       'bq,..:,@@*'   ,*      .  .\n              ,p$q8,:@)'  .p*'      .\n       .     '  . '@@Pp@@*'    .  .\n        .  . ..    Y7'.'     .  .\n                  :@):.\n                 .:@:'.\n               .::(@:.      -Sam Blumenstien-" << std::endl;
	}
	outfile.close();
}
