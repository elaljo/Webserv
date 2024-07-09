/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:24:12 by moelalj           #+#    #+#             */
/*   Updated: 2024/07/08 18:55:11 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"

void	check_line(std::vector<std::string> str)
{
	if (str.size() != 2)
	{
		std::cerr << "Error: invalide line" << std::endl;
		exit (1);
	}
}
void errors_needs_server(std::string key)
{
	if (compare(key, "listen"))
		x++;
	else if (compare(key, "serverName"))
		x++;
	else if (compare(key, "host"))
		x++;
	else if (compare(key, "maxBodySize"))
		x++;
	else
	{
		std::cerr << "Error: found Incomprehensible Key" << std::endl;
		exit (1);
	}
}