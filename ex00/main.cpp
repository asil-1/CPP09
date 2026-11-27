/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 22:44:21 by ldepenne          #+#    #+#             */
/*   Updated: 2026/11/27 01:59:51 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: The programme expects a file" << std::endl;
		return 0;
	}
	std::map<std::string, float>	database_m;
	//parsing database
	//	mettre database dans une map
	try {
		init_database(database_m);
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::map<std::string, float>::iterator it = database_m.begin();
		for (; it != database_m.end(); it++)
			std::cout << it->first << " | " << it->second << std::endl;
	(void)av;
	//proceder à l'echange -> parser file_input en meme temps
}
