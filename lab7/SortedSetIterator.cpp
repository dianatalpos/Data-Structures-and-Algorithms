
#include "SortedSetIterator.h"
#include "SortedSet.h"

//Complexity: O(lenght of tree)
SortedSetIterator::SortedSetIterator(const SortedSet& c): c{c}
{
	int rt = this->c.root;
	while (rt != -1)
	{
		this->s.push(rt);
		rt = this->c.elems[rt].left;
	}
	if (s.empty())
	{
		this->current = -1;
	}
	else
	{
		this->current = s.top();
	}
}


//Complexity O(lenght of tree)
void SortedSetIterator::first()
{
	while (this->s.size() != 0)
		s.pop();
	int rt = this->c.root;
	while (rt != -1)
	{
		this->s.push(rt);
		rt = this->c.elems[rt].left;
	}
	if (s.empty())
	{
		this->current = -1;
	}
	else
	{
		this->current = s.top();
	}
}

//O(lenght of tree)
void SortedSetIterator::next()
{
	if (!this->valid())
		throw std::exception();
	int n = this->s.top();
	this->s.pop();
	if (this->c.elems[n].right != -1)
	{
		n = this->c.elems[n].right;
		while (n != -1)
		{
			s.push(n);
			n = this->c.elems[n].left;
		}
	}
	if (!s.empty())
		this->current = s.top();
	else
		this->current = -1;
}

//Theta (1)
bool SortedSetIterator::valid() const
{
	if(this->current == -1)
		return false;
	return true;
}

/*void SortedSetIterator::jumpForward(int k)
{
	int x = 0;
	while (x < k)
	{
		if (!this->valid())
			throw std::exception();
		int n = this->s.top();
		this->s.pop();
		if (this->c.elems[n].right != -1)
		{
			n = this->c.elems[n].right;
			while (n != -1)
			{
				s.push(n);
				n = this->c.elems[n].left;
			}
		}
		if (!s.empty())
			this->current = s.top();
		else
			this->current = -1;
		x++;
	}
}
*/

void SortedSetIterator::jumpForward(int k)
{
	if(k <= 0)
		throw std::exception();
	int x = 0;
	while (x < k)
	{
		this->next();
		x++;
	}
}


//Theta(1)
TElem SortedSetIterator::getCurrent() const
{
	if (!valid())
		throw std::exception();
	return this->c.elems[this->current].info;
}


SortedSetIterator::~SortedSetIterator()
{
}
