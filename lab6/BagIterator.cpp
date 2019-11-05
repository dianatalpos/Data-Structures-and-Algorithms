#include "BagIterator.h"
#include <exception>

#define maximum 653530


BagIterator::BagIterator(const Bag & _b): b{_b}
{
	this->current = 0;
	while (this->current < this->b.m && this->b.T[this->current] == maximum)
	{
		this->current++;
	}
}


BagIterator::~BagIterator()
{
}

void BagIterator::first()
{
	this->current = 0;
	while (this->current < this->b.m && this->b.T[this->current] == maximum)
	{
		this->current++;
	}
}

void BagIterator::next()
{
	if (!this->valid())
		throw std::exception();
	this->current++;
	while (this->current < this->b.m && this->b.T[this->current] == maximum)
	{
		if (!this->valid())
			throw std::exception();
		this->current++;
	}
}

bool BagIterator::valid() const
{
	if(this->current >= this->b.m)
		return false;
	return true;
}

TElem BagIterator::getCurrent() 
{
	if (!this->valid())
		throw std::exception();
	return this->b.T[this->current];
}
