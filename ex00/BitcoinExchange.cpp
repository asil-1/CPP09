/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 22:55:19 by ldepenne          #+#    #+#             */
/*   Updated: 2026/11/27 02:02:04 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	parse_date(const std::string date) {
	if (date.size() != DATE_SIZE
		|| date[DASH_1] != '-' || date[DASH_2] != '-')
		throw std::runtime_error("Error: format of 'date' in database is invalide");
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == DASH_1 || i == DASH_2)
			continue ;
		if (date[i] < '0' || date[i] > '9')
			throw std::runtime_error("Error: the date is invalid in database");
	}

	int	year = std::atoi(date.substr(0, DASH_1).c_str());
	int	month = std::atoi(date.substr(DASH_1 + 1, DASH_2).c_str());
	int	day = std::atoi(date.substr(DASH_2 + 1).c_str());

	if (day < 1 || month < JANUARY || month > DECEMBER)
		throw std::runtime_error("Error: the date is invalid in database");
	if (day > 31)
		throw std::runtime_error("Error: the day is higher than 31 in database");
	if (month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER)
		if (day > 30)
			throw std::runtime_error("Error: the date is invalid in database");
	bool	bissextile;
	if (month == FEBRUARY)
	{
		bissextile = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
		if (bissextile)
		{
			if (day > 29)
				throw std::runtime_error("Error: the bissextile format is incorrect in database");
		}
		else if (day > 28)
			throw std::runtime_error("Error: the bissextile format is incorrect in database");
	}
}

void	init_database(std::map<std::string, float>& database_m) {
	if (FILE_DATABASE.empty())
		throw std::runtime_error("Error: database.csv is empty");
	if (FILE_DATABASE.substr(FILE_DATABASE.find_first_of(".")) != ".csv")
		throw std::runtime_error("Error: database is not a .csv file");

	std::ifstream	database;

	database.open(FILE_DATABASE.c_str());
	if (!database.is_open())
		throw std::runtime_error("Error: could not open file");
	std::string	gline;
	std::string	date;
	float		value;
	while (getline(database, gline))
	{
		if (gline == "date,exchange_rate")
			continue ;
		date = gline.substr(0, gline.find_first_of(','));
		parse_date(date);
		value = std::atof(gline.substr(gline.find_first_of(',') + 1).c_str());
		database_m.insert(std::make_pair(date, value));
	}
}
