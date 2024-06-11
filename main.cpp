#include "Config.hpp"

int check_which_context(std::string key)
{
	if (compare(key, "server"))
		return (1);
	return (0);
}
void	store_server_data()
{

}
config parse_file(std::string file_path)
{
	config Config;
	
	std::ifstream file(file_path);
	if (file.is_open())
	{
		std::string line;

		while (std::getline(file, line))
		{
			std::vector<std::string>str = splitString(trim(line), ' ');
			if (!str.empty())
			{
				if (check_only_key_value(trim(line)))
				{
					std::cout << line << std::endl;
					Config.set_Map(str[0], str[1]);
				}
				else
				{
					std::cout << line << std::endl;
					while (std::getline(file, line))
					{
						//if (check_which_context(str[0]));
							//server_config server;
						//store_server_data(server_config);
					//else
					//{
						//std::cout << "This context is not valid" << std::endl;
						//exit (1);
					}
				}
			}
		file.close();
		}
	}
	else
	{
		std::cerr << "No file to open!" << std::endl;
		exit (1);
	}
	return Config;
}

int main()
{
	std::string file_path = "nginx.conf";
	config config_file;
	
	config_file = parse_file(file_path);
	config_file.print_map();
	return (0);
}