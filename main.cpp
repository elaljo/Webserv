#include "Config.hpp"

int check_which_context(std::string key)
{
	if (compare(key, "server"))
		return (1);
	else if (compare(key, "location"))
		return (2);
	return (0);
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
					std::cout << "-" <<line << std::endl;
					Config.set_Map(str[0], str[1]);
				}
				else
				{
					if(check_which_context(str[0]))
					{
						server_config Server;

						while(std::getline(file, line))
						{
								std::vector<std::string>str1 = splitString(trim(line), ' ');
								if (!str1.empty())
								{
									if (check_only_key_value(trim(line)))
									{
										std::cout << "server- " << line << std::endl;
										Server.set_Map(str1[0], str1[1]);
									}
									else
									{
										if (check_which_context(str1[0]) == 2)
										{
											location Location;

											Location.set_uri(str1[1]);
											while (std::getline(file, line))
											{
												std::vector<std::string>str2 = splitString(trim(line), ' ');
												if (!str2.empty())
												{
													if (check_only_key_value(trim(line)))
													{
														std::cout << "locaiton- " << line << std::endl;
														Location.set_Map(str2[0], str2[1]);
													}
												}
											}
										}
									}
								}
						}
					}
				}
			}
		}
		file.close();
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
	server_config Server_config;
	
	config_file = parse_file(file_path);
	config_file.print_map();
	Server_config.print_map();
	return (0);
}