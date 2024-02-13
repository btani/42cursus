/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:12:04 by btani             #+#    #+#             */
/*   Updated: 2024/02/13 15:17:37 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int	main(void)
{
	const Animal* type = new Animal();
	const Animal* kitty = new Cat();
	const Animal* doggo = new Dog();
	
	const WrongAnimal*	wrong = new WrongAnimal();
	const WrongAnimal*	wrong_cat = new WrongCat();

	std::cout << std::endl;
	type->makeSound();
	kitty->makeSound();
	doggo->makeSound();
	wrong->makeSound();
	wrong_cat->makeSound();

	delete type;
	delete kitty;
	delete doggo;
	delete wrong;
	delete wrong_cat;
	
	return (0);
}

/*
int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	const WrongAnimal* h = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound(); //cat sound
	j->makeSound(); //dog sound
	h->makeSound(); //wrongcat sound

	delete meta;
	delete j;
	delete i;
	delete h;

	return 0;
}*/
