#include "Bag.h"
#include "BagIterator.h"
#include <iostream>
#define maximum 653530


//Complexity: Theta(1)
Bag::Bag()
{
	this->m = 13;
	this->T = new TElem[13];
	for (int i = 0; i < 13; i++)
	{
		this->T[i] = maximum;

	}
	this->sizee = 0;
}

//Complexity: O(m)
void Bag::add(TElem e)
{
	/*if (e == 13649)
		std::cout << "df";
	*/
	int i = 0;
	int pos = this->h(e, i);
	while (i < this->m && this->T[pos] != maximum)
	{
		/*if (i == 157324 && e == 13649)
			std::cout << "dw";
		(*/i++;
		pos = this->h(e, i);
	}
	if (i == this->m)
	{
		this->resize();
		this->add(e);
		return;
	}
	else
	{
		this->T[pos] = e;
		this->sizee++;
		return;
	}
}


//Complexity: O(m)
bool Bag::remove(TElem e)
{
	int i = 0;
	int position;
	while (i < this->m)
	{
		position = this->h(e, i);
		if (e == this->T[position])
		{
			this->T[position] = maximum;
			this->sizee--;
			return true;
		}
		i++;
	}
	return false;
}

//Complexity: O(m)
bool Bag::search(TElem e) const
{
	int i = 0;
	int position;
	while (i < this->m)
	{
		position = this->h(e, i);
		if (e == this->T[position])
			return true;
		i++;
	}
	return false;
}


//Complexity : Theta(m)
int Bag::nrOccurrences(TElem e) const
{
	int cont = 0;
	int i = 0;
	int position;
	while (i < this->m)
	{
		position = this->h(e, i);
		if (e == this->T[position])
			cont++;
		i++;
	}
	return cont;
}

//Complexity: Theta(1)
int Bag::size() const
{
	return this->sizee;
}

BagIterator Bag::iterator() const
{
	BagIterator it(*this);
	return it;
}


//Theta(1)



//Complexity: Theta(1)
bool Bag::isEmpty() const
{
	if (this->sizee == 0)
		return true;
	return false;
}



int Bag::removeAll(TElem e)
{
	bool i;
	int count = 0;
	while (1)
	{
		i = this->remove(e);
		if (i == false)
			return count;
		else
		{
			count++;
		}
	}
	return 0;
}


//Complexity: Theta(1)
Bag::~Bag()
{
	delete[] this->T;
}


TElem Bag::hashCode(TElem k) const
{
	if( k < 0)
		return -k;
	else return k;
}

//Complexity: Theta(1)
int Bag::h1(TElem k) const
{
	return k% this->m;
}


//Complexity: Theta(1)
int Bag::h2(TElem k) const
{
	return 1 +  ( k% (this->m - 1));
}


//Complexity: Theta(1)
int Bag::h(TElem k, int i) const
{
	long long a = i;
	long long k2= a * this->h2(this->hashCode(k)) % m;
	return (this->h1(this->hashCode(k)) + k2) % m;
}

void Bag::resize()
{
	int oldM = this->m;
	this->m = this->nextPrime();
	TElem* t = new TElem[oldM];
	for (int i = 0; i < oldM; i++)
		t[i] = this->T[i];
	delete[] this->T;
	TElem* tbig = new TElem[this->m];
	for (int i = 0; i < this->m; i++)
		tbig[i] = maximum;
	this->T = tbig;
	this->sizee = 0;
	for (int i = 0; i < oldM; i++)
	{
		if(t[i]!= maximum)
			this->add(t[i]);
	}
}

int Bag::nextPrime()
{
	int newM = (2 * this->m) - 1;
	while (1)
	{
		if (this->isPrime(newM))
			return newM;
		newM -= 2;
	}
	return 0;
}

bool Bag::isPrime(int n)
{
	if(n<2)
		return false;
	
	int d = 3;
	while (d*d <= n)
	{
		if (n%d == 0)
			return false;
		d += 2;
	}
	return true;
}
