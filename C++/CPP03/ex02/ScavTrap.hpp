#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
	
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& copy);
	~ScavTrap(void);

    ScavTrap& operator=(const ScavTrap& op);

	unsigned int getAttackDamage(void) const;
	void setAttackDamage(unsigned int attackDamage);
	void attack(const std::string& target);
	void guardGate(void);
};
