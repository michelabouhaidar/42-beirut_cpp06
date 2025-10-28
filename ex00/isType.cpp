/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isType.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:32:54 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/25 20:05:54 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isCharLiteral(std::string const& s)
{
	return s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0]));
}

bool isIntLiteral(std::string const& s)
{
	if (s.empty())
		return false;
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i == s.size())
		return false;
	for (; i < s.size(); i++)
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	return true;
}

bool isFloatPseudo(std::string const& s)
{
	return s == "nanf" || s == "+inff" || s == "-inff";
}

bool isDoublePseudo(std::string const& s)
{
	return s == "nan" || s == "+inf" || s == "-inf";
}

bool isFloatLiteral(std::string const& s)
{
	if (isFloatPseudo(s))
		return true;
	if (s.size() < 2 || s[s.size() - 1] != 'f')
		return false;
	std::string core = s.substr(0, s.size() - 1);
	size_t i = 0, dots = 0, digits = 0;
	if (core[i] == '+' || core[i] == '-')
		i++;
	for (; i < core.size(); i++)
	{
		if (core[i] == '.')
		{
			dots++;
			if (dots > 1)
				return false;
		}
		else if (std::isdigit(static_cast<unsigned char>(core[i])))
			digits++;
		else
			return false;
	}
	return dots == 1 && digits >= 1;
}

bool isDoubleLiteral(std::string const& s)
{
	if (isDoublePseudo(s))
		return true;
	size_t i = 0, dots = 0, digits = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (; i < s.size(); i++)
	{
		if (s[i] == '.')
		{
			dots++;
			if (dots > 1)
				return false;
		}
		else if (std::isdigit(static_cast<unsigned char>(s[i])))
			digits++;
		else
			return false;
	}
	return dots == 1 && digits >= 1;
}

bool isNan(double v)
{
	return v != v;
}

bool isPosInf(double v)
{
	const double inf = std::numeric_limits<double>::infinity();
	return v == inf;
}

bool isNegInf(double v)
{
	const double inf = std::numeric_limits<double>::infinity();
	return v == -inf;
}

bool isFinite(double v)
{
	return !isNan(v) && !isPosInf(v) && !isNegInf(v);
}
