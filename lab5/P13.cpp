#include "P13.h"
#include "Heap.h"
#include <exception>
#include <vector>

int get_max(vector<TElem>& elements)
{
	int max = INT_MIN;
	int poz = -1;
	int size = elements.size();
	for (int i = 0; i < size; i++) {
		if (elements[i] < max) {
			max = elements[i];
			poz = i;
		}
	}
	return poz;
}

void removeLast(vector<TElem>& elements, Relation r, int k)
{
	if (k <= 0)
	{
		throw exception();
	}
	else {
		Heap s;
		int size = elements.size();
		for (int i = 0; i < size; i++) {
			//add the elements to the heap
			s.add(elements[i], r);
		}
		while (k != 0)
		{
			//remove the last k elements 
			int max = get_max(elements);
			s.remove(r, max);
			k--;
		}

		elements = s.getAll();
	}

}