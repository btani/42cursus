#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
	
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap& copy);
	~FragTrap(void);

    FragTrap& operator=(const FragTrap& op);

	unsigned int getAttackDamage(void) const;
	void setAttackDamage(unsigned int attackDamage);
	void attack(const std::string& target);
	void highFivesGuys(void);
};
