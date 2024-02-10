#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap diamond("Ash");

	diamond.attack("Team Roket");
	diamond.takeDamage(0);
	diamond.beRepaired(0);
	diamond.highFivesGuys();	
		
	std::cout << std::endl;
	
	return 0;
}
