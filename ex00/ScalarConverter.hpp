/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:16:51 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/25 19:55:11 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <limits>
#include <cstdlib>
#include <cerrno>
#include <string>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter();
	public:
		static void convert(const std::string& literal);
};

bool parseInt(std::string const& s, int& out);
bool parseDouble(std::string const& s, double& out);

bool isCharLiteral(std::string const& s);
bool isIntLiteral(std::string const& s);
bool isFloatPseudo(std::string const& s);
bool isDoublePseudo(std::string const& s);
bool isFloatLiteral(std::string const& s);
bool isDoubleLiteral(std::string const& s);
bool isNan(double v);
bool isPosInf(double v);
bool isNegInf(double v);
bool isFinite(double v);

bool isPrintableChar(int v);
void printCharFromDouble(double v);
void printIntFromDouble(double v);
void printFloatFromDouble(double v);
void printDouble(double v);
void printAllFromDouble(double v);
void printAllImpossible();
void handleFloatPseudo(const std::string& s);
void handleDoublePseudo(const std::string& s);


#endif