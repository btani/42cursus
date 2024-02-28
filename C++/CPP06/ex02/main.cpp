#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

int main(void)
{
	Base* base0 = generate();
	sleep(1);
	Base* base1 = generate();
	sleep(1);
	Base* base2 = generate();

	std::cout << std::endl;
	std::cout << "Creation of the random objects" << std::endl;
	
	std::cout << std::endl;
	identify(base0);
	identify(*base0);
	std::cout << std::endl;
	identify(base1);
	identify(*base1);
	std::cout << std::endl;
	identify(base2);
	identify(*base2);
	std::cout << std::endl;

	delete base0;
	delete base1;
	delete base2;

	return 0;
}

