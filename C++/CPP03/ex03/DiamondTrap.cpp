#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap& copy): ClapTrap(copy)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = copy;
};

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap param constructor called" << std::endl;
	std::cout << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
};

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& op)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &op)
	{
		this->_name = op._name;
		this->_hitPoints = op._hitPoints;
		this->_energyPoints = op._energyPoints;
		this->_attackDamage = op.getAttackDamage();
	}
	return *this;
};

unsigned int DiamondTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
};

void DiamondTrap::setAttackDamage(unsigned int attackDamage)
{
	this->_attackDamage = attackDamage;
};

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << this->ClapTrap::_name << std::endl;
};
