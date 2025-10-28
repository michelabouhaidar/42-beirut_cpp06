/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:16:48 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/25 19:53:20 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string const& s)
{
	if (isCharLiteral(s))
	{
		unsigned char uc = static_cast<unsigned char>(s[0]);
		double d = static_cast<double>(uc);
		printAllFromDouble(d);
		return;
	}

	if (isIntLiteral(s))
	{
		int i;
		if (!parseInt(s, i))
		{
			printAllImpossible(); return;
		}
		double d = static_cast<double>(i);
		printAllFromDouble(d);
		return;
	}

	if (isFloatLiteral(s))
	{
		if (isFloatPseudo(s))
		{
			handleFloatPseudo(s); return;
		}
		std::string core = s.substr(0, s.size() - 1);
		double dcore;
		if (!parseDouble(core, dcore))
		{
			printAllImpossible(); return;
		}
		float f = static_cast<float>(dcore);
		double d = static_cast<double>(f);
		printAllFromDouble(d);
		return;
	}
	if (isDoubleLiteral(s))
	{
		if (isDoublePseudo(s))
		{
			handleDoublePseudo(s); return;
		}
		double d;
		if (!parseDouble(s, d))
		{
			printAllImpossible(); return;
		}
		printAllFromDouble(d);
		return;
	}

	printAllImpossible();
}
