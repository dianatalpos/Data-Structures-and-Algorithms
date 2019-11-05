#pragma once
#include "DynamicArray.h"


typedef int TElem;

class BagIterator;

class Bag {
	friend class BagIterator;

private:

	/*representation of Bag*/
	DynamicArray unique{};
	DynamicArray positions{};



public:

	//constructor

	Bag();

	
	void intersection(const Bag& b);
	
	//adds an element to the bag

	void add(TElem e);



	//removes one occurrence of an element from a bag

	//returns true if an element was removed, false otherwise (if e was not part of the bag)

	bool remove(TElem e);



	//checks if an element appearch is the bag

	bool search(TElem e);



	//returns the number of occurrences for an element in the bag

	int nrOccurrences(TElem e) const;



	//returns the number of elements from the bag

	int size() const;


	//returns an iterator for this bag

	BagIterator iterator() const;


	//checks if the bag is empty

	bool isEmpty() const;



	//destructor

	~Bag();

};