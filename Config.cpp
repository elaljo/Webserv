/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:42:02 by moelalj           #+#    #+#             */
/*   Updated: 2024/06/11 11:09:34 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"

void config::print_map()
{
	std::map<std::string, std::string>::iterator it;
	std::map<std::string, std::string> mp = get_Map();
	for(it = mp.begin(); it != mp.end(); it++){
		std::cout << "Key: " << it->first << " | value: " << it->second << std::endl;
	}
}

std::map<std::string, std::string> config::get_Map()const
{
	return (key_value);
}

void config::set_Map(std::string key, std::string value)
{
	key_value[key] = value;
}