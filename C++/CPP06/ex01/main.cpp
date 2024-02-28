/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:56:37 by btani             #+#    #+#             */
/*   Updated: 2024/02/25 16:56:39 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
    Data checker;
    Data *data;
    uintptr_t integer;

    checker.string = "btani";
    checker.i = 29;
    std::cout << "Initial data: " << checker.string << " " << checker.i << std::endl;
    
    integer = Serializer::serialize(&checker);
    std::cout << "Serialized data: " << integer << std::endl;
    
    data = Serializer::deserialize(integer);
    std::cout << "Deserialized data: " << data << std::endl;
    
	std::cout << "After the process the initial data '" << checker.string << ", " << checker.i << "' ";
	std::cout << "are the same after serialization '" << data->string << ", " << data->i << "'" << std::endl;
    return 0;
}
