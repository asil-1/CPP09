/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 04:43:52 by ldepenne          #+#    #+#             */
/*   Updated: 2026/11/27 18:06:35 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static e_operator	getOperator(char c)
{
	switch (c)
	{
		case '+':	return PLUS;
		case '-':	return MINUS;
		case '*':	return MULT;
		case '/':	return DIV;
		default:	return NONE;
	}
}

static int	calc(int a, int b, e_operator op)
{
	switch (op)
	{
		case PLUS:	return (a + b);
		case MINUS:	return (a - b);
		case MULT:
		{
			int	r = a * b;
			if ((a > 0 && b > 0 && r < 0) || (a < 0 && b > 0 && r > 0)
				|| (a > 0 && b < 0 && r > 0))
				throw std::runtime_error("Error: multiplication overflow");
			return (a * b);
		}
		case DIV:
		{
			if (b == 0)
				throw std::runtime_error("Error: division by 0 is impossible");
			return (a / b);
		}
		default:	return 0;
	}
}

int	solved_RPN(std::stack<int> &s, const std::string cal)
{
	int	a, b, c;
	size_t	i = 0;
	e_operator	op;

	for (; i < cal.size(); i++)
	{
		if (cal[i] == ' ')
			continue ;
		op = getOperator(cal[i]);
		if (cal[i] == NONE && !std::isdigit(cal[i]))
			throw std::runtime_error("Error: invalid charactere");
		else if (op == NONE)
			s.push(cal[i] - '0');
		else
		{
			if (s.size() < 2)
				throw std::runtime_error("Error: invalid operation");
			b = s.top();
			s.pop();
			a = s.top();
			s.pop();
			c = calc(a, b, op);
			s.push(c);
		}
	}
	if (s.size() > 1)
		throw std::runtime_error("Error: invalid operation");
	return s.top();
}
