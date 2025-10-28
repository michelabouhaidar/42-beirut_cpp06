/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:28:21 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/25 19:54:59 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

bool isPrintableChar(int v)
{
	return v >= 32 && v <= 126;
}

void printCharFromDouble(double v)
{
	std::cout << "char: ";
	if (!isFinite(v) || v < 0.0 || v > 127.0)
	{
		std::cout << "impossible\n";
		return;
	}
	char c = static_cast<char>(v);
	if (!isPrintableChar(static_cast<unsigned char>(c)))
	{
		std::cout << "Non displayable\n";
		return;
	}
	std::cout << "'" << c << "'" << "\n";
}

void printIntFromDouble(double v)
{
	std::cout << "int: ";
	if (!isFinite(v) ||
		v < static_cast<double>(std::numeric_limits<int>::min()) ||
		v > static_cast<double>(std::numeric_limits<int>::max()))
	{
		std::cout << "impossible\n";
		return;
	}
	int i = static_cast<int>(v);
	std::cout << i << "\n";
}

void printFloatFromDouble(double v)
{
	std::cout << "float: ";
	float f = static_cast<float>(v);

	const float finf = std::numeric_limits<float>::infinity();
	if (f != f)
	{
		std::cout << "nanf\n";
		return;
	}
	if (f == finf)
	{
		std::cout << "+inff\n";
		return;
	}
	if (f == -finf)
	{
		std::cout << "-inff\n";
		return;
	}

	std::streamsize oldprec = std::cout.precision();
	std::ios::fmtflags oldflags = std::cout.flags();
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout << std::setprecision(1) << f << "f\n";
	std::cout.precision(oldprec);
	std::cout.flags(oldflags);
}

void printDouble(double v)
{
	std::cout << "double: ";
	if (isNan(v))
	{
		std::cout << "nan\n";
		return;
	}
	if (isPosInf(v))
	{
		std::cout << "+inf\n";
		return;
	}
	if (isNegInf(v))
	{
		std::cout << "-inf\n";
		return;
	}

	std::streamsize oldprec = std::cout.precision();
	std::ios::fmtflags oldflags = std::cout.flags();
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout << std::setprecision(1) << v << "\n";
	std::cout.precision(oldprec);
	std::cout.flags(oldflags);
}

void printAllFromDouble(double v)
{
	printCharFromDouble(v);
	printIntFromDouble(v);
	printFloatFromDouble(v);
	printDouble(v);
}

void printAllImpossible()
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}

void handleFloatPseudo(const std::string& s)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	if (s == "nanf")
	{
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else if (s == "+inff")
	{
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
	}
	else
	{
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
}

void handleDoublePseudo(const std::string& s)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	if (s == "nan")
	{
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else if (s == "+inf")
	{
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
	}
	else
	{
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
}
