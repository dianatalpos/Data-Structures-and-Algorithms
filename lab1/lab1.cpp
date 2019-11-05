// lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Bag.h"
#include "BagIterator.h"
#include <crtdbg.h>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <stdlib.h>

int main()
{
	testAll();
	testAllExtended();

	Bag b{};
	b.add(5);
	b.add(5);
	b.add(3);
	b.add(5);
	b.add(1);
	Bag bb{ };
	bb.add(5);
	bb.add(5);
	bb.add(5);
	bb.add(3);
	bb.add(3);
	bb.add(5);
	bb.add(7);
	bb.add(5);

	b.intersection(bb);

	BagIterator it = b.iterator();
	while (it.valid()) {
		TElem e = it.getCurrent();
		it.next();
		std::cout << e<<" ";
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
