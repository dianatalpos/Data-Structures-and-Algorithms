// lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include "Bag.h"
#include "ShortTest.h"
#include "BagIterator.h"
#include "ExtendedTest.h"

using namespace std;

int main()
{

	testAll();
	testAllExtended();
	Bag b;
	b.add(5);
	b.add(5);
	b.add(5);
	b.add(2);
	b.add(3);
	b.add(1);
	b.add(5);
	b.add(4);
	int n;
	n = b.removeAll(5);
	cout << n << endl;
	BagIterator it = b.iterator();
	while (it.valid())
	{
		TElem e = it.getCurrent();
		it.next();
		cout << e << " ";
	}

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
