#pragma once
#include "Bag.h"

class BagIterator
{
	friend class Bag;
public:
	BagIterator(const Bag& b);
	~BagIterator();
private:
	//contains a reference of the container it iterates over
	const Bag& b;
	int current;

	/* representation specific for the iterator*/
public:
	//sets the iterator to the first element of the container

	void first();
	//moves the iterator to the next element

	//throws exception if the iterator is not valid

	void next();

	//checks if the iterator is valid

	bool valid() const;

	//returns the value of the current element from the iterator

	// throws exception if the iterator is not valid

	TElem getCurrent();
};

