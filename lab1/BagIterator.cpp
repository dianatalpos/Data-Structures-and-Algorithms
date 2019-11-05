#include "BagIterator.h"
#include "Bag.h"
#include <exception>

using namespace std;

// Complexity: Theta(1)
BagIterator::BagIterator(const Bag& c): bag (c)
{
	this->current = 0;
}


//Complexity: theta(1)
BagIterator::BagIterator(const BagIterator& it) : bag(it.bag )
{
	this->current = it.current;
}


//Complexity: theta(1)
void BagIterator::first()
{
	this->current = 0;
}

//Complexity: theta(1)
void BagIterator::next()
{
	if (!this->valid())
		throw exception();
	this->current++;
}


//Complexity: theta(1)
bool BagIterator::valid() const
{
	if (this->current < this->bag.size())
		return true;
	else
		return false;
}

//complexity: theta(1)
TElem BagIterator::getCurrent()
{
	if (!this->valid())
		throw exception();

	int position;
	position = this->bag.positions[this->current ];
	return this->bag.unique[position];
	return 0;
}