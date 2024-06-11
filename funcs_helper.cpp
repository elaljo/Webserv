#include "Config.hpp"

std::vector<std::string> splitString(const std::string &str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        if (!token.empty()){
            tokens.push_back(token);
        }
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
int compare(std::string key, std::string skey)
{
	unsigned i = 0;
	
	while (i < skey.length())
	{
		if (key[i] == skey[i])
			i++;
		else
			return 0;
	}
	return 1;
}
bool searchCharacter(const std::string& line, char target) {
    for (size_t i = 0; i < line.length(); i++) {
        if (line[i] == target) {
            return true;
        }
    }
    return false;
}

int check_only_key_value(std::string line)
{
    if (searchCharacter(line, ';') && !searchCharacter(line, '{'))
        return (1);
    return (0);
}