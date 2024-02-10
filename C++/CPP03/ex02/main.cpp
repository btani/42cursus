#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap frag("Ash");

	frag.printValues();

	frag.attack("Team Roket");
	frag.takeDamage(90);
	frag.beRepaired(20);
	frag.highFivesGuys();	
		
	std::cout << std::endl;
	
	return 0;
}
