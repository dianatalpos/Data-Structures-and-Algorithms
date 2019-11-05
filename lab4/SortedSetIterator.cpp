#include "SortedSetIterator.h"
#include "SortedSet.h"
#include <exception>

using namespace std;
SortedSetIterator::SortedSetIterator(const SortedSet& c): set(c)
{
	this->current = c.head;
}


void SortedSetIterator::first()
{
	this->current = this->set.head;
}

void SortedSetIterator::next()
{
	if (!this->valid())
		throw exception();
	this->current = this->set.elems[this->current].next;
}


bool SortedSetIterator::valid() const
{
	if (this->current == -1)
		return false;
	return true;
}

TElem SortedSetIterator::getCurrent() const
{
	if (!this->valid())
		throw exception();
	return this->set.elems[this->current].elem;
}




