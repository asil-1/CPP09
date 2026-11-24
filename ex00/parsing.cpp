/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 22:12:15 by ldepenne          #+#    #+#             */
/*   Updated: 2026/11/24 22:21:34 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

/* @todo throw an error here */
void	valid_date_format(std::string date) {

}

void	input_parsing(std::ifstream file) {
	std::string	gline;

	while (getline(file, gline))
	{
		//valid_date_format();
		//value == int between 0 - 100
	}
}

/* @todo adapt this for valid_date_format()
bool estDateValide(const std::string& s) {
    if (s.length() != 10 || s[4] != '-' || s[7] != '-') return false;
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;
        if (s[i] < '0' || s[i] > '9') return false;
    }

    int year = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
    int month = (s[5] - '0') * 10 + (s[6] - '0');
    int day = (s[8] - '0') * 10 + (s[9] - '0');

    if (month < 1 || month > 12 || day < 1) return false;

    int max_jours = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        max_jours = 30;
    } else if (month == 2) {
        bool bissextile = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        max_jours = bissextile ? 29 : 28;
    }

    return day <= max_jours;
}
*/
