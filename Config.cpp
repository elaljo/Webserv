/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:42:02 by moelalj           #+#    #+#             */
/*   Updated: 2024/06/09 19:43:36 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"

std::vector<std::string> splitString(const std::string &str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::string trim(const std::string& str) {
    std::string trimmedString = str;
    
    // Remove leading spaces
    size_t start = 0;
    while (start < trimmedString.length() && std::isspace(trimmedString[start])) {
        ++start;
    }
    trimmedString.erase(0, start);
    
    // Remove trailing spaces
    size_t end = trimmedString.length() - 1;
    while (end > 0 && std::isspace(trimmedString[end])) {
        --end;
    }
    trimmedString.erase(end + 1);
    
    return trimmedString;
}

void config::print_map()
{
	std::map<std::string, std::string>::iterator it;
	std::map<std::string, std::string> mp = get_Map();
	for(it = mp.begin(); it != mp.end(); it++){
		std::cout << "Key: " << it->first << " / value: " << it->second << std::endl;
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

int compare(std::string key, std::string skey)
{
	int i = 0;
	
	while (i < skey.length())
	{
		if (key[i] == skey[i])
			i++;
		else
			return 0;
	}
	return 1;
}

int	check_only_key(std::string line)
{
	if (compare(trim(line), "root"))
		return 1;
	return 0;
}

//int only_key_value()
//{
	
//}
config parse_file(std::string file_path)
{
	config k1;

	std::ifstream file(file_path);
	if (file.is_open())
	{
		std::string line;

		while (std::getline(file, line))
		{
			if (check_only_key(line))
			{
				std::vector<std::string>str = splitString(line, ' ');
				k1.set_Map(trim(str[0]), trim(str[1]));
			}
			std::cout << line << std::endl;
		}
		file.close();
	}
	else
	{
		std::cerr << "No file to open!" << std::endl;
		exit (1);
	}
	return k1;
}

int main()
{
	std::string file_path = "nginx.conf";
	config k1;

	k1 = parse_file(file_path);
	k1.print_map();
	return (0);
}