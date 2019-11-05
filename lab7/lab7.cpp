// lab7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <assert.h>

bool r3(TComp e1, TComp e2) {
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}


int main()
{
	testAll();
	testAllExtended();

	SortedSet s{r3};
	s.add(1);
	s.add(5);
	s.add(7);
	s.add(2);
	s.add(3);
	s.add(10);
	SortedSetIterator it = s.iterator();
	it.first();
	TElem e;
	e = it.getCurrent();
	it.next();
	int dim = 1;
	TElem x[10];
	x[0] = e;
	while (it.valid()) {
		assert(r3(e, it.getCurrent()));
		e = it.getCurrent();
		x[dim++] = e;
		try
		{
			it.jumpForward(2);
		}
		catch (std::exception& e)
		{
			;
		}
	}
	for (int i = 0; i < dim; i++)
	{
		std::cout << x[i] << " ";
	}


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
