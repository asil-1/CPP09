/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 22:45:32 by ldepenne          #+#    #+#             */
/*   Updated: 2026/11/27 03:19:53 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>
# include <map>

# define FILE_DATABASE std::string("data.csv")

enum	e_month {
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

enum	e_format {
	DATE_SIZE = 10,
	DASH_1 = 4,
	DASH_2 = 7
};

/* @return could throw an error */
void	init_database(std::map<std::string, float>& database_m);
void	exchange_rate(const std::map<std::string, float>& database_m, const std::string file);

#endif
