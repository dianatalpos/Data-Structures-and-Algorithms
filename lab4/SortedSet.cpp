#include "SortedSet.h"
#include "SortedSetIterator.h"

//Complexity: theta(capacity)
SortedSet::SortedSet(Relation r)
{
	this->head = -1;
	this->tail = -1;
	this->sizee = 0;
	this->firstEmpty = 0;
	this->capacity = 3;
	this->elems = new DllElem[3];
	for (int i = 0; i < this->capacity-1; i++)
	{
		DllElem d;
		d.next = i + 1;
		d.prev = i - 1;
		this->elems[i] = d ;
		
	}
	DllElem d;
	d.next = -1;
	d.prev = this->capacity - 2;
	this->elems[this->capacity -1] = d;
	this->relation = r;
}


//Complexity: Theta(1)
bool SortedSet::isEmpty() const
{
	if (this->sizee == 0)
		return true;
	return false;
}


//Complexity O(n)
bool SortedSet::remove(TComp e)
{
	int i = this->head;
	int prev = -1;
	while (i != -1 && this->elems[i].elem != e)
	{
		prev = i;
		i = this->elems[i].next;
	}
	if (i == -1)
		return false;
	if (prev == -1)
	{
			// elem, first empty
		this->head = this->elems[this->head].next;
		if(this->head != -1)
			this->elems[this->head].prev = -1;
		this->elems[i].next = this->firstEmpty;
		this->elems[i].prev = -1;
		this->firstEmpty = i;
		this->sizee--;
		return true;
	}
	else
	{
		if (i == this->tail)
		{
			//tail, first empty, size;
			this->tail = this->elems[i].prev;
			this->elems[this->tail].next = -1;
			this->elems[i].next = this->firstEmpty;
			this->elems[i].prev = -1;
			this->firstEmpty = i;
			this->sizee--;
			return true;
		}
		else
		{
			//next elem prev, prev elem urm, first empty;
			this->elems[prev].next = this->elems[i].next;
			this->elems[this->elems[i].next].prev = prev;
			this->elems[i].next = this->firstEmpty;
			this->elems[i].prev = -1;
			this->firstEmpty = i;
			this->sizee--;
			return true;
		}
	}
}


//Complexity: O(n) , n = the size of the set
bool SortedSet::search(TElem elem) const
{
	int i;
	i = this->head;
	if (i == -1)
	{
		return false;
	}
	while (i != -1)
	{
		if (elem == this->elems[i].elem)
			return true;
		i = this->elems[i].next;
	}
	return false;

}


//Complexity: theta(1)
int SortedSet::size() 
{
	return this->sizee;
}



//Complexity O(n + m) , n the numbers of empty elements from the array, m - 2*capacity
/*
void SortedSet::resize()
{ 
	int pos;
	if (this->firstEmpty == -1) {
		DllElem d;
		d.next = this->capacity + 1;
		d.prev = -1;
		this->elems[this->capacity] = d;
		this->firstEmpty = this->capacity;
	}
	else {
		for (int i = this->firstEmpty; ; i = this->elems[i].next) {
			if (this->elems[i].next == -1) {
				DllElem d;
				d.next = this->capacity + 1;
				d.prev = i;
				this->elems[i] = d;

				this->elems[i].next = this->capacity;

				break;
			}
		}
	}

	for (int i = this->capacity+1; i < 2 * this->capacity-1; i++)
	{
		DllElem d;
		d.next = i + 1;
		d.prev = i - 1;
		this->elems[i] = d;
	}

	DllElem d;
	d.next = -1;
	d.prev = 2*this->capacity - 2;
	this->elems[2*this->capacity - 1] = d ;
	this->capacity *= 2;
}
*/

void SortedSet::resize()
{
	DllElem* newe = new DllElem[2 * this->capacity];
	for (int i = 0; i < 2*this->capacity - 1; i++)
	{
		DllElem d;
		d.next = i + 1;
		d.prev = i - 1;
		newe[i] = d;

	}
	DllElem d;
	d.next = -1;
	d.prev = 2*this->capacity - 2;
	newe[2*this->capacity - 1] = d;
	
	


	for (int i = 0; i < this->capacity; i++)
	{ 
		newe[i].elem = this->elems[i].elem;
		newe[i].next = this->elems[i].next;
		newe[i].prev = this->elems[i].prev;
	}

	int pos;
	if (this->firstEmpty == -1) {
		DllElem d;
		d.next = this->capacity + 1;
		d.prev = -1;
		newe[this->capacity] = d;
		this->firstEmpty = this->capacity;
	}
	else {
		for (int i = this->firstEmpty; ; i = newe[i].next) {
			if (newe[i].next == -1) {
				DllElem d;
				d.next = this->capacity + 1;
				d.prev = i;
				newe[i] = d;

				newe[i].next = this->capacity;

				break;
			}
		}
	}

	d.next = -1;
	d.prev = 2 * this->capacity - 2;
	newe[2 * this->capacity - 1] = d;

	this->capacity *= 2;
	delete[] this->elems;
	this->elems = newe;
}

//Complexity:O(n),  n= the size of the set
bool SortedSet::add(TComp e)
{
	if (this->sizee == this->capacity)
		this->resize();
	int i = this->head;
	int prev = -1;
	while (i != -1 && this->relation(e, this->elems[i].elem) == false)
	{
		prev = i;
		i = this->elems[i].next;
	}
	//head ori tail ori empty list 
	if (prev == -1)
	{
		if (i == -1)
		{
			this->head = this->firstEmpty;
			this->tail = this->firstEmpty;
			this->firstEmpty = this->elems[this->head].next;
			this->elems[this->head].elem = e;
			this->elems[this->head].next = -1;
			this->elems[this->head].prev = -1;
			this->sizee++;
			return true;
		}
		else
		{
			if (e == this->elems[i].elem)
				return false;
			int pos = this->firstEmpty;
			this->firstEmpty = this->elems[this->firstEmpty].next;
			this->elems[pos].elem = e;
			this->elems[pos].next = this->head;
			this->elems[pos].prev = -1;
			this->elems[this->head].prev = pos;
			this->head = pos;
			this->sizee++;
			return true;
		}
	}
	else
	{
		if (i == -1)
		{
			if (this->elems[prev].elem == e) {
				return false;
			}
			int pos = this->firstEmpty;
			this->firstEmpty = this->elems[pos].next;
			//tail, elem
			this->elems[pos].elem = e;
			this->elems[pos].next = -1;
			this->elems[pos].prev = prev;
			this->elems[prev].next = pos;
			this->tail = pos;
			this->sizee++;
			return true;
		} 
		else
		{
			if (e == this->elems[i].elem || e == this->elems[prev].elem)
				return false;
			//next elem anterior, prev elem urmator, elem, size, 
			int pos = this->firstEmpty;
			this->firstEmpty = this->elems[pos].next;
			this->elems[pos].elem = e;
			this->elems[pos].next = i;
			this->elems[pos].prev = prev;
			this->elems[i].prev = pos;
			this->elems[prev].next = pos;
			this->sizee++;
			return true;
		}
	}
	return false;
}


SortedSetIterator SortedSet::iterator() const
{
	SortedSetIterator it(*this );
	return it;
}


//Complexity: theta(1)
SortedSet::~SortedSet()
{
	delete [] this->elems;
}


void SortedSet::intersection(SortedSet set)
{
	int i = this->head;
	while(i != -1)
	{
		bool elem_set;
		elem_set = set.search(this->elems[i].elem);
		if (elem_set == false)
		{
			int pos = i;
			i = this->elems[i].next;
			this->remove(this->elems[pos].elem);
		}
		else
			i = this->elems[i].next;
	}
}

SortedSet::SortedSet(const SortedSet &set) {
	this->capacity = set.capacity;
	this->sizee = set.sizee;
	this->firstEmpty = set.firstEmpty;
	this->head = set.head;
	this->tail = set.tail;

	this->elems = new DllElem[this->capacity];
	for (int i = 0; i < this->capacity; ++i) {
		this->elems[i].elem = set.elems[i].elem;
		this->elems[i].prev = set.elems[i].prev;
		this->elems[i].next = set.elems[i].next;
	}
}



