/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:07:28 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/10/28 23:12:15 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

static void print_data(const char* title, const Data* d) {
    std::cout << title << "\n";
    if (!d) {
        std::cout << "  (null)\n";
        return;
    }
    std::cout << "  address : " << d << "\n";
    std::cout << "  name    : " << d->name << "\n";
    std::cout << "  age     : " << d->age << "\n";
	std::cout << "  weight  : " << d->weight << "\n";
    std::cout << "  height  : " << d->height << "\n";
}

int main() {
    Data original;
    original.name = "Michel";
    original.age = 32;
    original.weight = 85.0;
	original.height = 185.7;

    Data* ptr = &original;
    print_data("Original Data", ptr);
    uintptr_t raw = Serializer::serialize(ptr);
    std::cout << "\nSerialized (uintptr_t): " << raw << "\n";
    Data* restored = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer   : " << restored << "\n\n";
    if (restored == ptr) {
        std::cout << "Success\n";
    } else {
        std::cout << "Failure\n";
    }
    print_data("Restored Data", restored);

    return 0;
}
