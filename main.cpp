#include "Config.hpp"

int check_server_context(std::string key, std::string bracket)
{
	int i = 0;
	if (compare(key, "server"))
		i++;
	else
	{
		std::cerr << "Error: Server context does not found !!" << std::endl;
		exit (1);
	}
	if (compare(bracket, "{"))
		return (1);
	else
	{
		std::cerr << "Error: Server openning bracket does not found !!" << std::endl;
		exit (1);
	}
	return (0);
}

int check_location_context(std::string key, std::string bracket)
{
	int i = 0;
	if (compare(key, "location"))
		i++;
	else
	{
		std::cerr << "Error: location context does not found !!" << std::endl;
		exit (1);
	}
	if (compare(bracket, "["))
		return (1);
	else
	{
		std::cerr << "Error: locaiton openning bracket does not found !!" << std::endl;
		exit (1);
	}
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
			check_line(str);
			if (!str.empty())
			{
				if (check_only_key_value(trim(line)))
					Config.set_Map(str[0], remv_last_char(str[1]));
				else
				{
					if(check_server_context(str[0], str[1]))
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
										check_line(str1);
										errors_needs_server(str1[0]);
										if(compare(str1[0], "listen"))
											Server.store_ports(str1[1]);
										Server.set_Map(str1[0], remv_last_char(str1[1]));
									}
									else
									{
										if (str1.size() != 3)
										{
											std::cerr << "Error: Invalide line at locaiton context" << std::endl;
											exit (1);
										}
										if (check_location_context(str1[0], str1[2]))
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
												if (str2.size() != 2)
												{
													std::cerr << "Error: Invalide line at location context" << std::endl;
													exit (1);
												}
												if (!str2.empty())
												{
													if (check_only_key_value(trim(line)))
														Location.set_Map(str2[0], splitString(remv_last_char(str2[1]), ','));
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