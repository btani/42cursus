/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:00:21 by btani             #+#    #+#             */
/*   Updated: 2024/02/25 18:24:23 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <time.h>

Base::~Base(void)
{
	std::cout << "Base destructor called" << std::endl;	
};

Base* generate(void)
{
	srand(time(0));
	int randomic = rand() % 3; //randomic number between 0-2
	switch(randomic)
	{
		case 0:
			std::cout << "A is created" << std::endl;
			return (new A());
		case 1:
			std::cout << "B  is created" << std::endl;
			return (new B());
		case 2:
			std::cout << "C is created" << std::endl;
			return (new C());
		default:
			return NULL;		
	}
};

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class pointed: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class pointed: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class pointed: C" << std::endl;
	else
		std::cout << "Class pointed unknown" << std::endl;
};

//Using a pointer inside this function is forbidden.
void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Class referenced: A" << std::endl;
		return;
	}
	catch(...) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Class referenced: B" << std::endl;
		return;
	}
	catch(...) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Class referenced: C" << std::endl;
		return;
	}
	catch(...) {}
	std::cout << "Class referenced unknown" << std::endl;
};
/*dynamic-cast: used to handle polymorphism. If a pointer to a base class,
we can't directly know the actual derived type of the object it points to.
We use dynamic-cast when ther is a hierarchy of classes, to know the type 
of the object at runtime; it check if the cast is a valid type for the object.*/
