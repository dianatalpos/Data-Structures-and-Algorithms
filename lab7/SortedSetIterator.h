#pragma once
#include "SortedSet.h"
#include <stdlib.h>
#include <stack>

//unidirectional iterator for a container

class SortedSetIterator {
	friend class SortedSet;
private:
	struct Node
	{
		TComp info;
		int left;
		int right;
		int parent;
	};
	std::stack<int> s;
	const SortedSet& c;
	int current;

	/* representation specific for the iterator*/

public:


	SortedSetIterator(const SortedSet& c);



	//sets the iterator to the first element of the container

	void first();

	//moves the iterator to the next element

	//throws exception if the iterator is not valid

	void next();

	//checks if the iterator is valid
	bool valid() const;

	//returns the value of the current element from the iterator
	// throws exception if the iterator is not valid

	void jumpForward(int k);

	TElem getCurrent() const;

	~SortedSetIterator();

};


