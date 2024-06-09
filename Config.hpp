/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:41:47 by moelalj           #+#    #+#             */
/*   Updated: 2024/06/09 19:41:48 by moelalj          ###   ########.fr       */
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
		void set_Map(std::string key, std::string value);
		std::map<std::string, std::string> get_Map() const;
		void print_map();
};