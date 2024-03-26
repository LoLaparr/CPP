#pragma once

#include "ICharacter.hpp"

class Character: public ICharacter
{
private:
						Character(void);
	std::string			name;
	int					equipped;
	AMateria			*inventory[4];
public:
						Character(const std::string &name);
						Character(const Character &other);
	virtual				~Character(void);

	const std::string	&getName(void) const;

	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter &target);

	Character			&operator=(const Character &other);
};

Character::Character(const std::string &name): name(name), equipped(0)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

Character::Character(const Character &other): name(other.name), equipped(0)
{
	for (int i = 0; i < other.equipped; i++)
		this->equip(other.inventory[i]->clone());
	for (int i = this->equipped; i < 4; i++)
		this->inventory[i] = 0;
}

Character::~Character()
{
	for (int i = 0; i < this->equipped; i++)
	{
		if (this->inventory[i] != 0)
			delete this->inventory[i];
	}
}


const std::string &Character::getName(void) const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (m == 0)
		return ;
	if (this->equipped == 4)
		return ;
	for (int i = 0; i < this->equipped; i++)
	{
		if (this->inventory[i] == m)
			return ;
	}
	this->inventory[this->equipped++] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->equipped || this->inventory[idx] == 0)
		return ;
	for (int i = idx; i < 3; i++)
	{
		this->inventory[i] = this->inventory[i + 1];
		this->inventory[i + 1] = 0;
	}
	this->equipped--;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= this->equipped || this->inventory[idx] == 0)
		return ;
	this->inventory[idx]->use(target);
}

Character &Character::operator=(const Character &other)
{
	this->name = other.name;
	for (int i = 0; i < this->equipped; i++)
		delete this->inventory[i];
	this->equipped = 0;
	for (int i = 0; i < other.equipped; i++)
		this->equip(other.inventory[i]->clone());
	for (int i = this->equipped; i < 4; i++)
		this->inventory[i] = 0;
	return (*this);
}
