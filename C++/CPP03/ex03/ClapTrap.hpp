#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

class ClapTrap
{
	protected:
	
	std::string _name;
	int _hitPoints; // health
	int _energyPoints; // energy to attack/repair (attacking/repairing cost 1 energy point)
	int _attackDamage; // value of the damage, set in main

	public:
	
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& copy);
	~ClapTrap(void);

    ClapTrap& operator=(const ClapTrap& op);

	unsigned int getAttackDamage(void) const;
	void setAttackDamage(unsigned int attackDamage);
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void printValues(void);
};

#endif
