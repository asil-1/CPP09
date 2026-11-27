/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 22:55:19 by ldepenne          #+#    #+#             */
/*   Updated: 2026/11/27 03:54:55 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	valid_date(const std::string date) {
	if (date.size() != DATE_SIZE
		|| date[DASH_1] != '-' || date[DASH_2] != '-')
		throw std::runtime_error("Error: a format of date is invalide");
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == DASH_1 || i == DASH_2)
			continue ;
		if (date[i] < '0' || date[i] > '9')
			throw std::runtime_error("Error: the date is invalid");
	}

	int	year = std::atoi(date.substr(0, DASH_1).c_str());
	int	month = std::atoi(date.substr(DASH_1 + 1, DASH_2).c_str());
	int	day = std::atoi(date.substr(DASH_2 + 1).c_str());

	if (day < 1 || month < JANUARY || month > DECEMBER)
		throw std::runtime_error("Error: the date is invalid");
	if (day > 31)
		throw std::runtime_error("Error: the day is higher than 31");
	if (month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER)
		if (day > 30)
			throw std::runtime_error("Error: the date is invalid");
	bool	bissextile;
	if (month == FEBRUARY)
	{
		bissextile = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
		if (bissextile)
		{
			if (day > 29)
				throw std::runtime_error("Error: the bissextile format is incorrect");
		}
		else if (day > 28)
			throw std::runtime_error("Error: the bissextile format is incorrect");
	}
}

static void	valid_value(const float value) {
	if	(value < 0)
		throw std::runtime_error("Error: not a positive number");
	if (value > 1000)
		throw std::runtime_error("Error: too large a number");
}

void	init_database(std::map<std::string, float>& database_m) {
	if (FILE_DATABASE.empty())
		throw std::runtime_error("Error: database.csv is empty");
	if (FILE_DATABASE.substr(FILE_DATABASE.find_first_of(".")) != ".csv")
		throw std::runtime_error("Error: database is not a .csv file");

	std::ifstream	database;

	database.open(FILE_DATABASE.c_str());
	if (!database.is_open())
		throw std::runtime_error("Error: could not open database.csv");
	std::string	gline;
	std::string	date;
	float		value;
	while (getline(database, gline))
	{
		if (gline == "date,exchange_rate")
			continue ;
		date = gline.substr(0, gline.find_first_of(','));
		valid_date(date);
		value = std::atof(gline.substr(gline.find_first_of(',') + 1).c_str());
		database_m.insert(std::make_pair(date, value));
	}
}

void	exchange_rate(const std::map<std::string, float>& database_m, const std::string file) {
	std::ifstream	fChange;

	fChange.open(file.c_str());
	if (!fChange.is_open())
		throw std::runtime_error("Error: could not open input file");

	std::string	gline;
	std::string	date;
	float		value;
	while (getline(fChange, gline))
	{
		if (gline == "date | value")
			continue ;
		date = gline.substr(0, gline.find_first_of(" | "));
		try {
			valid_date(date);
			value = std::atof(gline.substr(gline.find_first_of(" | ") + 3).c_str());
			if (gline.find_first_of(" | ") > gline.size())
			{
				std::cout << "Error: value empty -> " << date << std::endl;
				continue ;
			}
			valid_value(value);
		} catch (std::exception& e) {
			std::cout << "(" << date << ") " << e.what() << std::endl;
			continue;
		}
		if (gline.size() < DATE_SIZE)
			return ;
		float	result;
		if (std::atoi(date.c_str()) > std::atoi(database_m.rbegin()->first.c_str()))
			result = database_m.rbegin()->second * value;
		else
			result = database_m.lower_bound(date)->second * value;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
	(void)database_m;
}
