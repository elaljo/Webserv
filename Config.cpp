/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:42:02 by moelalj           #+#    #+#             */
/*   Updated: 2024/06/29 16:53:33 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"

void config::print_map()
{
	std::cout << "	*map for the config*" << std::endl;
	std::map<std::string, std::string>::iterator it;
	std::map<std::string, std::string> mp = get_Map();
	for(it = mp.begin(); it != mp.end(); it++){
		std::cout << "Key: " << it->first << " | value: " << it->second << std::endl;
	}
}
void server_config::print_map()
{
	std::cout << "	*map for the server*" << std::endl;
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
void	server_config::set_Map(std::string key, std::string value)
{
	key_value[key] = value;
}
std::map<std::string, std::string> server_config::get_Map()const
{
	return (key_value);
}
void	location::set_Map(std::string key, std::string value)
{
	key_value[key] = value;	
}
std::map<std::string, std::string> location::get_Map()const
{
	return (key_value);
}
void	location::set_uri(std::string URI)
{
	this->uri = URI;
}