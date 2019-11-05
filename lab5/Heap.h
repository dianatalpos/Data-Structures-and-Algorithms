#pragma once
#include <utility>
#include <vector>

using namespace std;

typedef int TElem;

typedef bool(*Relation)(TElem p1, TElem p2);

class Heap
{
private:

	TElem capacity;
	TElem size;
	TElem* elems;
public:
	Heap();
	vector < TElem> getAll();
	void resize();
	void add(TElem e, Relation r);
	void up(int i, Relation r);
	void remove(Relation r, TElem el);
	~Heap();
};