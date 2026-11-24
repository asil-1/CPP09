/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 19:45:21 by ldepenne          #+#    #+#             */
/*   Updated: 2026/11/24 22:14:18 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>

class	BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(std::string file);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange &operator=(const BitcoinExchange& other);
		~BitcoinExchange();

	private:
		std::string		_fname;
		std::ifstream	_fvalues;
};

void	input_parsing(std::ifstream file);

#endif
