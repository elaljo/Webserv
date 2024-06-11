/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:41:47 by moelalj           #+#    #+#             */
/*   Updated: 2024/06/11 11:44:41 by moelalj          ###   ########.fr       */
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
};

class server_config {
	private:
		std::map<std::string, std::string> 	key_value;
		std::vector<location> 							locations;
};

class config {
	private:
		std::map<std::string, std::string> key_value;
		std::vector<server_config> 			server_config;
	public:
		//void	add(server_config server) {
		//	server_config.push_back(server);
		//}
		void set_Map(std::string key, std::string value);
		std::map<std::string, std::string> get_Map() const;
		void print_map();
};

std::vector<std::string> splitString(const std::string &str, char delimiter);
std::string trim(const std::string& str);
int compare(std::string key, std::string skey);
bool searchCharacter(const std::string& line, char target);
int check_only_key_value(std::string line);