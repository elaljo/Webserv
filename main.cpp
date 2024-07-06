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
					Config.set_Map(str[0], str[1]);
				else
				{
					if(check_which_context(str[0]))
					{
						server_config Server;

						while(std::getline(file, line))
						{
							if (searchCharacter(line, '}'))
							{
								Config.add(Server);
								break;
							}
								std::vector<std::string>str1 = splitString(trim(line), ' ');
								if (!str1.empty())
								{
									if (check_only_key_value(trim(line)))
									{
										if(compare(str1[0], "listen"))
											Server.store_ports(str1[1]);
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
												if (searchCharacter(line, ']'))
												{
													Server.add(Location);
													break;
												}
												std::vector<std::string>str2 = splitString(trim(line), ' ');
												if (!str2.empty())
												{
													if (check_only_key_value(trim(line)))
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
		file.close();
	}
	else
	{
		std::cerr << "No file to open!" << std::endl;
		exit (1);
	}
	return Config;
}

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		std::string file_path = argv[1];

		config config_file;
	
		config_file = parse_file(file_path);
		config_file.print_map();
	}
	else
		std::cerr << "Error:\n Please Enter A Good Params!!" << std::endl;
	return (0);
}