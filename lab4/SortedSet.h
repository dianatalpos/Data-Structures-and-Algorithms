#pragma once

#include <stdlib.h>
#include <iostream>
#include <vector>


typedef int TElem;

typedef TElem TComp;



typedef bool(*Relation)(TComp, TComp);

class SortedSetIterator;

class SortedSet {
	friend class SortedSetIterator;

private:

	/*Representation of the SortedSet*/

	struct DllElem{
		TElem elem;
		int next;
		int prev;
	};

	DllElem* elems;
	int head;
	int tail;
	int sizee;
	int firstEmpty;
	int capacity;
	Relation relation;




public:


	// Copy constructor
	SortedSet(const SortedSet &set);

	//constructor

	SortedSet(Relation r);



	//adds an element to the sorted set

	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 

	//it returns false

	bool add(TComp e);



	//removes an element from the sorted set

	//if the element was removed, it returns true, otherwise false

	bool remove(TComp e);



	//checks if an element is in the sorted set

	bool search(TElem elem) const;





	//returns the number of elements from the sorted set

	int size();



	//checks if the sorted set is empty

	bool isEmpty() const;



	//returns an iterator for the sorted set

	SortedSetIterator iterator() const;


	void intersection(SortedSet set);


	// destructor
	~SortedSet();

private:
	void resize();





};
