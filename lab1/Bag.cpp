#include "Bag.h"
#include "BagIterator.h"
#include<math.h>

//complexity: theta(1)
Bag::Bag()
{
}

//complexity: theta(1)
Bag::~Bag()
{

}


//complexity: o(n) , n - numar elemente unice
void Bag::add(TElem e)
{
	TElem i;
	TElem pos = -1;
	for (i = 0; i < this->unique.getSize(); i++)
	{
		if (e == this->unique[i])
		{
			pos = i;
			break;
		}
	}
	if (pos != -1)
	{
		this->positions.add(pos);
	}
	else
	{
		this->unique.add(e);
		this->positions.add(this->unique.getSize() - 1);
	}
}


//complexity: o(n) , n -numar elemente din bag
bool Bag::remove(TElem e)
{
	TElem i;
	int freq = 0;
	int pos = -1;
	int pos_unique = -1;
	for (i = 0; i < this->positions.getSize(); i++)
	{
		if (e == this->unique[this->positions[i]])
		{
			/*
			1 2 2 2 2 5 7 2 2

			u: 1 2 5 7
			p: 1 2 2 2 2 3 4 2 2 
			*/
			freq++;
			pos = i;
			pos_unique = this->positions[i];
		}
	}

	if (freq > 1)
	{
		this->positions[pos] = this->positions[this->positions.getSize() - 1];
		this->positions.removeLast();
		return true;
	}

	if (freq == 1)
	{
		int old_pos = this->unique.getSize() - 1;
		this->unique[pos_unique] = this->unique[old_pos];
		this->positions[pos] = this->positions[this->positions.getSize() - 1];
		this->positions.removeLast();
		for (i = 0; i < this->positions.getSize(); i++)
		{
			if (this->positions[i] == old_pos)
				this->positions[i] = pos_unique;
		}
		this->unique.removeLast();

		return true;
	}
	return false;
}

//complexity: o(n) , n - nr elem unice 
bool Bag::search(TElem e)
{
	TElem i;
	for (i = 0; i < this->unique.getSize(); i++)
	{
		if ( this->unique[i] == e)
		{
			return 1;
		}
	}
	return 0;
}


void Bag::intersection(const Bag& b)
{
	int i = 0, nOcurrent, nObag, diff;
	for (i = 0; i < this->unique.getSize(); i++)
	{
		nOcurrent = this->nrOccurrences(this->unique[i]);
		nObag = b.nrOccurrences(this->unique[i]);
		diff =nOcurrent - nObag;
		if (diff > 0)
		{
			int j;
			for (j = 0; j < diff; j++)
				this->remove(this->unique[i]);
		}
	}
}

//complexity: theta(1)
int Bag::size() const
{
	return this->positions.getSize();
}

//complexity: theta(n) , n - nr elemente bag
int Bag::nrOccurrences(TElem e) const
{
	TElem i;
	int freq = 0;
	for (i = 0; i < this->positions.getSize(); i++)
	{
		int position = this->positions[i];
		if (e == this->unique[position])
		{
			freq++;
		}
	}
	return freq;
}

//complexity: theta(1)
bool Bag::isEmpty() const
{
	if (this->positions.getSize() == 0)
		return true;
	return false;
		
}

//complexity: theta(1) 
BagIterator Bag::iterator() const
{
	BagIterator it( *this );
	return it;
}


