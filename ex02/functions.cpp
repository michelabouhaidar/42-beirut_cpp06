/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:14:47 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/31 18:36:49 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	int r = std::rand() % 3;
	std::cout << r << std::endl;
	switch(r)
	{
		case 0:
			std::cout << "Generated type:A\n";
			return new A();
		case 1:
			std::cout << "Generated type: B\n";
			return new B();
		default:
			std::cout << "Generated type: C\n";
			return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type identified (ptr): A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Type identified (ptr): B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Type identified (ptr): C\n";
	else
		std::cout << "Type identified (ptr): Unknown\n";
}

void identify(Base& p)
{
	try 
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type identified (ref): A\n";
		return;
	}
	catch (...) {}
	try 
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type identified (ref): B\n";
		return;
	}
	catch (...) {}
	try 
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type identified (ref): C\n";
		return;
	}
	catch (...) {}
	std::cout << "Type identified (ref): Unkown\n";
}