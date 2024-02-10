#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << std::endl;
	std::cout << "ClapTrap default constructor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << std::endl;
	std::cout << "ClapTrap copy constructor called" << std::endl;

	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
};

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << std::endl;
	std::cout << "ClapTrap param constructor called" << std::endl;
};

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& op)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &op)
	{
		this->_name = op._name;
		this->_hitPoints = op._hitPoints;
		this->_energyPoints = op._energyPoints;
		this->_attackDamage = op.getAttackDamage();
	}
	return *this;
};

unsigned int ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
};

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	this->_attackDamage = attackDamage;
};

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
        std::cout << "ClapTrap " << this->_name << " has no more hit points." << std::endl;
        return;   
    }
	if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target <<
					", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no more hit/energy points or no damage!" << std::endl;
};

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->_hitPoints)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points damage." << std::endl;
		std::cout << "ClapTrap is dead!" << std::endl;
		this->_hitPoints = 0;
		return;
	}
	else
		this->_hitPoints -= amount;
};

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no more hit points." << std::endl;
		return;
	}
	if (amount > 0)
	{
		if (this->_energyPoints == 0)
		{
		std::cout << "ClapTrap " << this->_name << " has no more energy points left!" << std::endl;
			return ;
		}
		std::cout << "ClapTrap " << this->_name << " restored " << amount << " hit points!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " is damaged." << std::endl;
};

void ClapTrap::printValues(void)
{
	std::cout << std::endl << "ClapTrap " << this->_name << " values: " << std::endl;
	std::cout << this->_hitPoints << " hit points" << std::endl;
	std::cout << this->_energyPoints << " energy points" << std::endl;
	std::cout << this->_attackDamage << " attack damage" << std::endl << std::endl;
};
