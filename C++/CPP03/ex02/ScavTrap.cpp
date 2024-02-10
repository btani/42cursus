#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap& copy): ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;

	*this = copy;
};

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	
	std::cout << "ScavTrap param constructor called" << std::endl;
	std::cout << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
};

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrav destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& op)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &op)
	{
		this->_name = op._name;
		this->_hitPoints = op._hitPoints;
		this->_energyPoints = op._energyPoints;
		this->_attackDamage = op.getAttackDamage();
	}
	return *this;
};

unsigned int ScavTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
};

void ScavTrap::setAttackDamage(unsigned int attackDamage)
{
	this->_attackDamage = attackDamage;
};


void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
        std::cout << "ScavTrap " << this->_name << " has no more hit points." << std::endl;
        return;   
    }
	if (this->_energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target <<
					", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ScavTrap " << this->_name << " has no more hit/energy points or no damage!" << std::endl;
};

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
};
