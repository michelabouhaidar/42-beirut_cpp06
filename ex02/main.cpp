/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:25:05 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/31 18:39:06 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	std::srand(std::time(NULL));
	Base* basePtr = generate();
	std::cout << " -- Using pointer -- ";
	identify(basePtr);
	delete basePtr;
	std::cout << std::endl;
	basePtr = generate();
	std::cout << " -- Using reference -- ";
	identify(*basePtr);
	delete basePtr;
	std::cout << std::endl;
	return 0;
}
