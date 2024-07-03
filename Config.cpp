/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:42:02 by moelalj           #+#    #+#             */
/*   Updated: 2024/07/03 22:11:32 by moelalj          ###   ########.fr       */
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

	std::vector<server_config> servers = getServers();
	
	for (size_t i = 0; i < servers.size(); i++){
		std::cout << "	*map for the server[" << i <<"]*" << std::endl;
		std::map<std::string, std::string>::iterator its;
		std::map<std::string, std::string> mps = servers[i].get_Map();
		for(its = mps.begin(); its != mps.end(); its++){
			std::cout << "Key: " << its->first << " | value: " << its->second << std::endl;
		}
		std::vector<location> locations = servers[i].getLocations();
		for(size_t j = 0; j < locations.size(); j++){
			std::cout << "	*map for the location[" << j <<"]*" << std::endl;
			std::cout << "URI -> " << locations[j].get_uri() << std::endl;
			std::map<std::string, std::string>::iterator itl;
			std::map<std::string, std::string> mpl = locations[j].get_Map();
			for(itl = mpl.begin(); itl != mpl.end(); itl++){
			std::cout << "Key: " << itl->first << " | value: " << itl->second << std::endl;
		}
		}
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
std::string location::get_uri()
{
	return (this->uri);
}