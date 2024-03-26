#pragma once

# include <string>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
	int				current;
	AMateria		*sources[4];
public:
					MateriaSource(void);
					MateriaSource(const MateriaSource &other);
	virtual			~MateriaSource(void);

	void			learnMateria(AMateria *m);
	AMateria		*createMateria(const std::string &type);

	MateriaSource	&operator=(const MateriaSource &other);
};

MateriaSource::MateriaSource(): current(0)
{
	for (size_t i = 0; i < 4; i++)
		this->sources[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other): current(0)
{
	for (int i = 0; i < other.current; i++)
		this->learnMateria(other.sources[i]->clone());
	for (size_t i = 0; i < 4; i++)
		this->sources[i] = 0;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->current; i++)
		delete this->sources[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->current  == 4 || m == 0)
		return ;
	for (int i = 0; i < this->current; i++)
	{
		if (this->sources[i] == m)
			return ;
	}
	this->sources[this->current++] = m;
}

AMateria* MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < this->current; i++)
	{
		if (this->sources[i]->getType() == type)
			return (this->sources[i]->clone());
	}
	return (0);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	for (int i = 0; i < this->current; i++)
		delete this->sources[i];
	this->current = 0;
	for (int i = 0; i < other.current; i++)
		this->learnMateria(other.sources[i]->clone());
	for (int i = 0; i < 4; i++)
		this->sources[i] = 0;
	return (*this);
}
