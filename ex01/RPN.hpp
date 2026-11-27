/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 04:43:03 by ldepenne          #+#    #+#             */
/*   Updated: 2026/11/27 17:42:45 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cstdlib>
# include <limits>
# include <stack>

enum	e_operator {
	PLUS,
	MINUS,
	MULT,
	DIV,
	NONE
};

int	solved_RPN(std::stack<int> &s, const std::string cal);

#endif
