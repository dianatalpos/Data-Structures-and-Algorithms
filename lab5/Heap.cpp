
#include "Heap.h"
//Complexity: Theta(1)
Heap::Heap()
{
	this->capacity = 10;
	this->size = 0;
	this->elems = new TElem[10];
}

//Complexity: Theta(n)
vector<TElem> Heap::getAll()
{
	vector<TElem> v1;
	for (int i = 0; i < this->size; i++)
	{

		v1.push_back(this->elems[i]);
	}
	return v1;
}

//Complexity: Theta(n)
void Heap::resize()
{
	int new_cap = this->capacity * 2;
	TElem* elemsss = new TElem[new_cap];
	for (int i = 0; i < this->size; i++) {
		elemsss[i] = this->elems[i];
	}
	delete this->elems;
	this->elems = elemsss;
	this->capacity = new_cap;
}

void Heap::add(TElem e, Relation r)
{

	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->up(this->size, r);
	this->size++;
}

void Heap::up(int i, Relation r)
{
	TElem e = this->elems[i];
	int k = i; //the actual position of the eleemnt which needs to go up
	int p = k / 4; //the father of k
	//search for the position between the succesors
	if (!r(this->elems[p], e) && p == 0) {
		this->elems[k] = this->elems[p];
		k = p;
		p = p / 4;
	}
	while (p >= 1 && !r(this->elems[p], e))
	{
		//the elements go down until the rule is respected
		this->elems[k] = this->elems[p];
		int aux = p;
		p = p--;
	}
	//put the element o the position k  
	this->elems[k] = e;
	int el = this->elems[k];
	k = i;
	while (p != this->size) {
		//swap between element from position k and with the elem from position p(father) 
		if (!r(this->elems[p], this->elems[k]))
		{
			int aux = this->elems[k];
			for (int h = k; h > p; h--) {
				this->elems[h] = this->elems[h - 1];
			}
			this->elems[p] = aux;
		}
		p++;
	}
}

//Complexity: O(n)
void Heap::remove(Relation r, TElem el)
{

	int i = 0;
	for (i = 0; i < this->size; i++)
		if (el == this->elems[i])
			break;
	for (int j = i; j < this->size - 1; j++) {
		this->elems[i] = this->elems[i + 1];
	}
	this->size = this->size - 1;
}

Heap::~Heap()
{
	delete[] this->elems;
}
