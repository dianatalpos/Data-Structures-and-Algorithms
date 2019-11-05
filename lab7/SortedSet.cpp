
#include "SortedSet.h"
#include "SortedSetIterator.h"

//Theta(1)
SortedSet::SortedSet(Relation r)
{
	this->r = r;
	this->capacity = 100;
	this->elems = new Node[this->capacity];
	this->firstEmpty = 0;
	this->sizee = 0;
	this->root = -1;
	for (int i = 0; i < this->capacity -1; i++)
	{
		this->elems[i].left = i + 1;
	}
	this->elems[this->capacity -1].left = -1;
}

//O(lenght of tree)
bool SortedSet::add(TComp e)
{
	int rt = this->root;
	if (this->sizee == this->capacity)
		this->resize();
	int prev = -1;
	if (this->sizee == 0)
	{
		Node n;
		n.info = e;
		n.left = -1;
		n.right = -1;
		int poz = this->firstEmpty;
		this->firstEmpty = this->elems[poz].left;
		this->root = poz;
		this->elems[poz] = n;
		this->sizee++;
		return true;
	}
	while (rt != -1)
	{
		prev = rt;
		if (this->r(e, this->elems[rt].info))
		{
			if (this->elems[rt].info == e)
				return false;
			rt = this->elems[rt].left;
		}
		else
		{
			if (this->elems[rt].info == e)
				return false;
			rt = this->elems[rt].right;
			
		}
	}
	if (this->elems[prev].info == e)
		return false;
	Node n;
	n.info = e;
	n.left = -1;
	n.right = -1;
	int poz = this->firstEmpty;
	this->firstEmpty = this->elems[poz].left;
	this->elems[poz] = n;
	this->sizee++;
	if (this->r(e, this->elems[prev].info))
		this->elems[prev].left = poz;
	else
		this->elems[prev].right = poz;

	return true;
}

//O(lenght of tree)
bool SortedSet::remove(TComp e)
{
	if (this->sizee == 0)
		return false;
	int rt = this->root;
	int prev = -1;
	while (rt!=-1 && this->elems[rt].info != e)
	{
		prev = rt;
		if (this->r(e, this->elems[rt].info))
			rt = this->elems[rt].left;
		else
			rt = this->elems[rt].right;
	}
	if (rt == -1)
		return false;
	if (this->elems[rt].left == -1)
	{
		if (this->elems[rt].right == -1)
		{
			if (rt == this->root)
			{
				this->root = -1;
			}
			else
				if (this->r(e, this->elems[prev].info))
					this->elems[prev].left = -1;
				else
					this->elems[prev].right = -1;
		}
		else
		{
			if (rt == this->root)
			{
				this->root = this->elems[rt].right;
			}
			else
				if (this->elems[prev].left == rt)
				{
					this->elems[prev].left = this->elems[rt].right;
				}
				else
				{
					this->elems[prev].right = this->elems[rt].right;
				}
		}

		int fir = this->firstEmpty;
		this->firstEmpty = rt;
		this->elems[this->firstEmpty].left = fir;
		this->sizee--;
		return true;
	}
	else
	{
		if (this->elems[rt].right == -1)
		{
			if (rt == this->root)
				this->root = this->elems[rt].left;
			else
				if (this->elems[prev].left == rt)
				{
					this->elems[prev].left = this->elems[rt].left;
				}
				else
				{
					this->elems[prev].right = this->elems[rt].left;
				}

			int fir = this->firstEmpty;
			this->firstEmpty = rt;
			this->elems[this->firstEmpty].left = fir;
			this->sizee--;
			return true;
		}
		else
		{
			int prevpos = rt;
			int pos = this->elems[rt].right;
			while (this->elems[pos].left != -1)
			{
				prevpos = pos;
				pos = this->elems[pos].left;
			}
			this->elems[rt].info = this->elems[pos].info;
			if (this->elems[pos].right != -1)
				this->elems[prevpos].left = this->elems[pos].right;
			else
				this->elems[prevpos].left = -1;

			int fir = this->firstEmpty;
			this->firstEmpty = pos;
			this->elems[this->firstEmpty].left = fir;
			this->sizee--;
			return true;
		}
	}
	return false;
}



//Complexity: O(lenght of tree)
bool SortedSet::search(TElem elem) const
{
	int rt = this->root;
	while (rt != -1 && this->elems[rt].info != elem)
	{
		if (this->r(elem, this->elems[rt].info))
			rt = this->elems[rt].left;
		else
			rt = this->elems[rt].right;
	}
	if (rt != -1 && this->elems[rt].info == elem)
		return true;
	return false;
}


//Theta(1)
int SortedSet::size() const
{
	return this->sizee;
}

//Theta(1)
bool SortedSet::isEmpty() const
{
	if (this->sizee == 0)
		return true;
	return false;
}

//Theta(1)
SortedSetIterator SortedSet::iterator() const
{
	SortedSetIterator it(*this);
	return it;
}

//Theta(1)
SortedSet::~SortedSet()
{
	delete[] this->elems;
}

//Complexity: Theta of new size
void SortedSet::resize()
{
	this->capacity = 2 * this->capacity;
	Node* newt = new Node[this->capacity];
	for (int i = 0; i < this->capacity; i++)
	{
		//this->elems[i].left = i + 1;
		newt[i].left = i + 1;
	}
	//this->elems[29].left = -1;
	newt[this->capacity].left = -1;
	for (int i = 0; i < this->capacity / 2; i++)
		newt[i] = this->elems[i];
	this->firstEmpty = this->capacity / 2;
	delete[] this->elems;
	this->elems = newt;

}
