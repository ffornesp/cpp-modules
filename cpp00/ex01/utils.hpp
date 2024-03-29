/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:58:46 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/07 13:16:08 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <iostream>

std::string	trimString(std::string str);
bool		errorMessage(std::string str, bool out);
bool		emptyCheck(std::string str, bool flag);
bool		fieldCheck(std::string str, bool flag);

#endif