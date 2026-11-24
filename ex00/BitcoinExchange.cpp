/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 19:50:05 by ldepenne          #+#    #+#             */
/*   Updated: 2026/11/24 22:17:16 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { throw std::runtime_error("Error: This class requires a file as an argument"); }

BitcoinExchange::BitcoinExchange(std::string file) : _fname(file), _fvalues(file.c_str()) {
	if (!_fvalues.is_open())
		throw std::runtime_error("Error: could not open file");
	try {
		input_parsing(_fvalues);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { _fname = other._fname;	_fvalues.open(_fname.c_str()); }

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange& other) { _fname = other._fname; _fvalues.open(_fname.c_str()); return *this; }

BitcoinExchange::~BitcoinExchange() {}


