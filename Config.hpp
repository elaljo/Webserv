 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:41:47 by moelalj           #+#    #+#             */
/*   Updated: 2024/06/25 21:36:17 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>

class location {
	private:
		std::string uri;
		std::map<std::string, std::string> key_value;
	public:
		void set_uri(std::string URI);
		std::string get_uri();
		void	set_Map(std::string key, std::string value);
		std::map<std::string, std::string> get_Map() const;
};

class server_config {
	private:
		std::map<std::string, std::string> 	key_value;
		std::vector<location> 							locations;
		std::vector<std::string>						ports;
	public:
		void	add(location location) {
			locations.push_back(location);
		}
		std::vector<location> getLocations() {
			return locations;
		}
		void	set_Map(std::string key, std::string value);
		std::map<std::string, std::string> get_Map() const;
		void	store_ports(std::string p_line);
		std::vector<std::string> get_ports();
};

class config {
	private:
		std::map<std::string, std::string> key_value;
		std::vector<server_config> 			server_configs;
	
	public:
		void	add(server_config server) {
			server_configs.push_back(server);
		}
		std::vector<server_config> getServers() {
			return server_configs;
		}
		void set_Map(std::string key, std::string value);
		std::map<std::string, std::string> get_Map() const;
		void print_map();
};

std::vector<std::string> splitString(const std::string &str, char delimiter);
std::string trim(const std::string& str);
int compare(std::string key, std::string skey);
bool searchCharacter(const std::string& line, char target);
int check_only_key_value(std::string line);