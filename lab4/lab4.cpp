// lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ShortTest.h"
#include "SortedSet.h"
#include "SortedSetIterator.h"
#include "ExtendedTest.h"
#include <iostream>
#include <crtdbg.h>


bool rLessEqualq(TComp e1, TComp e2) {
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}


int main()
{
	{
		testAll();
		testAllExtended();
		SortedSet s{ rLessEqualq };
		s.add(1);
		s.add(10);
		s.add(5);
		s.add(3);
		s.add(8);
		s.add(9);
		SortedSet s2{ rLessEqualq };
		s2.add(1);
		s2.add(7);
		s2.add(10);
		s2.add(5);
		s2.add(2);
		s.intersection(s2);
		SortedSetIterator it = s.iterator();
		TComp e;
		while (it.valid()) {
			e = it.getCurrent();
			std::cout << e << " ";
			it.next();
		}
	}
	_CrtDumpMemoryLeaks();
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
