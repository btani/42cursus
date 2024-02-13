/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:12:04 by btani             #+#    #+#             */
/*   Updated: 2024/02/13 15:43:25 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    j->makeSound();
    i->makeSound();
   
    delete j;
    delete i;
	
	const AAnimal*	nbr_anim[10];
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		nbr_anim[i] = new Dog();
	std::cout << std::endl;
    std::cout << "AAnimals from 0 to 4 set with cat ideas\n\n";
	std::cout << std::endl;
	for (int i = 5; i < 10; i++)
		nbr_anim[i] = new Cat();
	std::cout << std::endl;
    std::cout << "AAnimals from 5 to 9 set with cat ideas\n\n";
	for (int i = 0; i < 10; i++)
		delete nbr_anim[i];
    std::cout << "Deleted all animals\n\n";

	return (0);
}


