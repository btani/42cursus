
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:

	std::string _name;
	
	public:
	
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& copy);
	~DiamondTrap(void);

    DiamondTrap& operator=(const DiamondTrap& op);

	unsigned int getAttackDamage(void) const;
	void setAttackDamage(unsigned int attackDamage);
	using ScavTrap::attack;
	void whoAmI(void);
};

/*using : in this scope is used to bring from ScavTrap the "attack" function into the cutrrent scope:
we can use "attack" directly in the main function without any other specification*/
