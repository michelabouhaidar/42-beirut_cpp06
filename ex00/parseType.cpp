/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:12:48 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/25 20:04:04 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool parseInt(std::string const& s, int& out)
{
	errno = 0;
	char* end = 0;
	long v = std::strtol(s.c_str(), &end, 10);
	if (errno == ERANGE)
		return false;
	if (end == s.c_str() || *end != '\0')
		return false;
	if (v < std::numeric_limits<int>::min() || v > std::numeric_limits<int>::max())
		return false;
	out = static_cast<int>(v);
	return true;
}

bool parseDouble(std::string const& s, double& out)
{
	errno = 0;
	char* end = 0;
	out = std::strtod(s.c_str(), &end);
	if (errno == ERANGE)
		return false;
	if (end == s.c_str() || *end != '\0')
		return false;
	return true;
}

