/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:12:04 by btani             #+#    #+#             */
/*   Updated: 2024/02/13 18:12:28 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    j->makeSound();
    i->makeSound();
   
    delete j;
    delete i;
	
	const Animal*	nbr_anim[10];
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		nbr_anim[i] = new Dog();

	std::cout << std::endl;
	
    std::cout << "Animals from 0 to 4 set with dog ideas\n" << std::endl;
	for (int i = 5; i < 10; i++)
		nbr_anim[i] = new Cat();

	std::cout << std::endl;
	
    std::cout << "Animals from 5 to 9 set with cat ideas\n" << std::endl;
	for (int i = 0; i < 10; i++)
		delete nbr_anim[i];
    std::cout << "Deleted all animals" << std::endl;

	return (0);
}


