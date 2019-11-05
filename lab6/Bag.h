#pragma once



typedef int TElem;



class Bag {

	friend class BagIterator;
private:

	/*representation of Bag*/

	int m;
	TElem *T;
	int sizee;


public:
	//constructor
	Bag();

	//adds an element to the bag
	void add(TElem e);

	//removes one occurrence of an element from a bag

	//returns true if an element was removed, false otherwise (if e was not part of the bag)

	bool remove(TElem e);

	//checks if an element appearch is the bag

	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag

	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;
	

	int removeAll(TElem e);

	//destructor

	~Bag();
private:
	TElem hashCode(TElem k) const;
	int h1(TElem k) const;
	int h2(TElem k) const;
	int h(TElem k, int i) const;
	void resize();
	int nextPrime();
	bool isPrime(int n);

};