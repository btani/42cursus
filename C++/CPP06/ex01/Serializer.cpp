/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:56:57 by btani             #+#    #+#             */
/*   Updated: 2024/02/25 16:56:59 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
    std::cout << "Serializer default constructor called" << std::endl;
};

Serializer::Serializer(Serializer const& copy)
{
    std::cout << "Serializer copy constructor called" << std::endl;
    *this = copy;
};

Serializer::~Serializer(void)
{
    std::cout << "Serializer destructor called" << std::endl;
};

Serializer& Serializer::operator=(Serializer const& op)
{
    std::cout << "Serializer assignation operator called" << std::endl;
    if (this != &op)
    {
        *this = op;
    }
    return *this;
};

/*reinterpret-cast reinterprets the binary pattrn as a value 
of the new type, in this case we use it to convert the pointer
type into an integer type*/
uintptr_t Serializer::serialize(Data* ptr)
{
    std::cout << "Serialization" << std::endl;
    return reinterpret_cast<uintptr_t>(ptr);
};

Data* Serializer::deserialize(uintptr_t raw)
{
    std::cout << "Deserialization" << std::endl;
    return reinterpret_cast<Data*>(raw);
};
