#include "ListIterator.h"
#include"SortedIndexedList.h"
#include <exception>

using namespace std;

//complexity: theta(1)
ListIterator::ListIterator(const SortedIndexedList& c) : list ( c )
{
	this->current = c.head;
}


//complexity: theta(1)
void ListIterator::first()
{
	this->current = this->list.head;

}

//complexity: theta(1)
void ListIterator::next()
{
	if (! this->valid() ) 
	{
		throw exception();
	}
	this->current = this->current->next;
}


//complexity: theta(1)
bool ListIterator::valid() const
{
	if (this->current == nullptr)
		return false;
	return true;
}

//complexity: theta(1)
TComp ListIterator::getCurrent() const
{
	if (!this->valid())
		throw exception();
	return this->current->info;
}






