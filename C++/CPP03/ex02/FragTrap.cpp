#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
};

FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
};

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap param constructor called" << std::endl;
	std::cout << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
};

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrav destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& op)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &op)
	{
		this->_name = op._name;
		this->_hitPoints = op._hitPoints;
		this->_energyPoints = op._energyPoints;
		this->_attackDamage = op.getAttackDamage();
	}
	return *this;
};

unsigned int FragTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
};

void FragTrap::setAttackDamage(unsigned int attackDamage)
{
	this->_attackDamage = attackDamage;
};


void FragTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
        std::cout << "FragTrap " << this->_name << " has no more hit points." << std::endl;
        return;   
    }
	if (this->_energyPoints > 0)
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target <<
					", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "FragTrap " << this->_name << " has no more hit/energy points or no damage!" << std::endl;
};

void FragTrap::highFivesGuys(void)
{
	std::cout << "Hey guys, I'm " << this->_name << "! Give me a high fives!" << std::endl;
};
