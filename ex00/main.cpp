/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 22:44:21 by ldepenne          #+#    #+#             */
/*   Updated: 2026/11/27 02:48:18 by ldepenne         ###   ########.fr       */
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
	try {
		init_database(database_m);
		exchange_rate(database_m, av[1]);
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
