/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 04:40:48 by ldepenne          #+#    #+#             */
/*   Updated: 2026/11/27 06:13:37 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char ** av)
{
	if (ac < 2)
	{
		std::cerr << "Error: the program expects an RPN argument" << std::endl;
		return 0;
	}
	std::stack<int>	s;
	int	result;

	try {
		result = solved_RPN(s, av[1]);
		std::cout << result << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
