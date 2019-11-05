#pragma once
#include <utility>
#include <vector>

using namespace std;

typedef int TElem;

typedef bool(*Relation)(TElem p1, TElem p2);

int get_max(vector<TElem>& elements);

//removes the last k elements from the vector (considering the relation)
//if k is less than or equal to zero, throws an exception
//if k is greater than the size of the array, all elements will be removed
void removeLast(vector<TElem>& elements, Relation r, int k);
