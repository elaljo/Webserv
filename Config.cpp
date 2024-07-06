/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:42:02 by moelalj           #+#    #+#             */
/*   Updated: 2024/07/06 01:00:50 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"

void config::print_map()
{
	std::cout << "	- Config map -" << std::endl;
	std::cout << "----------------------------"<< std::endl;
	std::map<std::string, std::string>::iterator it;
	std::map<std::string, std::string> mp = get_Map();
	for(it = mp.begin(); it != mp.end(); it++){
		std::cout << "Key: " << it->first << " | value: " << it->second << std::endl;
	}
	std::cout << "----------------------------"<< std::endl;


	std::vector<server_config> servers = getServers();
	
	for (size_t i = 0; i < servers.size(); i++){
		std::cout << "	- Map dyal Server[" << i <<"]-" << std::endl;
		std::cout << "----------------------------"<< std::endl;

		std::map<std::string, std::string>::iterator its;
		std::map<std::string, std::string> mps = servers[i].get_Map();
		std::cout << "hahoma ports fwahd vector smito ports nadyin" << std::endl;
		std::vector<std::string>::iterator pts;
		std::vector<std::string> pps = servers[i].get_ports();
		for(pts = pps.begin(); pts!= pps.end(); pts++){
			std::cout <<  *pts << std::endl;
		}
		std::cout << "----------------------------"<< std::endl;

		for(its = mps.begin(); its != mps.end(); its++){
			std::cout << "Key: " << its->first << " | value: " << its->second << std::endl;
		}
		std::cout << "----------------------------"<< std::endl;
		std::vector<location> locations = servers[i].getLocations();
		for(size_t j = 0; j < locations.size(); j++){
			std::cout << "	- Map dyal location[" << j <<"]-" << std::endl;
			std::cout << "----------------------------"<< std::endl;
			std::cout << "URI -> " << locations[j].get_uri() << std::endl;
			std::map<std::string, std::string>::iterator itl;
			std::map<std::string, std::string> mpl = locations[j].get_Map();
			for(itl = mpl.begin(); itl != mpl.end(); itl++){
			std::cout << "Key: " << itl->first << " | value: " << itl->second << std::endl;
		}
		std::cout << "----------------------------"<< std::endl;
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

std::string remv_last_char(std::string token)
{
    size_t i = 0;
    std::string n_token;

    while (i < token.size() - 1)
    {
        n_token.push_back(token[i]);
        i++;
    }
    return (n_token);
}

void	server_config::store_ports(std::string p_line){
	this->ports = splitString(remv_last_char(p_line), ',');
}
std::vector<std::string> server_config::get_ports(){
	return ports;
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