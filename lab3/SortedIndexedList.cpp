#include "SortedIndexedList.h"
#include "ListIterator.h"
#include <exception>

using namespace std;

//complexity: theta(1)
SortedIndexedList::SortedIndexedList(Relation r)
{
	this->head = nullptr;
	this->relation = r;
	this->size_list = 0;
}

//complexity: theta(1)
int SortedIndexedList::size() const
{
	return this->size_list;
}

//complexity: theta(1)
bool SortedIndexedList::isEmpty() const
{
	if (this->size_list == 0)
		return true;
	return false;
}

//complexity: theta(n) , n- the given position
TComp SortedIndexedList::getElement(int pos) const
{
	if (pos < 0 || pos >= this->size_list)
		throw exception();
	int i = 0;
	Node *node;
	node = this->head;
	for(i = 0 ; i< pos;i++)
	{
		node = node->next;
	}
	return node->info;
}

//complexity: o(n)
void SortedIndexedList::add(TComp e)
{
	Node *node = new Node;
	node->info = e;
	Node *go;
	Node *prev = nullptr;
	go = this->head;
	while (go != nullptr && this->relation(go->info, e) == true)
	{
		prev = go;
		go = go->next;
	}
	if (prev == nullptr)
	{
		if (go == nullptr)
		{
			node->next = nullptr;
			this->head = node;
		}
		else
		{
			node->next = this->head;
			this->head = node;
		}
	}
	else
		if (go == nullptr)
		{
			prev->next = node;
			node->next = nullptr;
		}
		else
		{
			node->next = go;
			prev->next = node;
		}
	this->size_list++;
}

//complexity: theta(pos)
TComp SortedIndexedList::remove(int pos)
{
	if (pos < 0 || pos >= this->size_list)
		throw exception();
	
	Node *go;
	go = this->head;
	if (pos == 0)
	{
		this->head = this->head->next;
		TComp inf;
		inf = go->info;
		delete go;
		this->size_list--;
		return inf;
	}
	int i = 0;
	Node *prev;
	prev = nullptr;
	for (i = 0; i < pos; i++)
	{
		prev = go;
		go = go->next;
	}
	
	TComp inf;
	inf = go->info;
	prev->next = go->next;
	delete go;

	this->size_list--;
	return inf;

}


//complexity: theta(n)
SortedIndexedList::~SortedIndexedList()
{
	Node* node;
	node = this->head;
	while (this->head != nullptr)
	{
		this->head = this->head->next;
		delete node;
		node = this->head;
	}
	delete node;
}

//complexity: o(n)
int SortedIndexedList::search(TComp e) const
{
	int i = 0;
	Node *go;
	go = this->head;
	while (go != nullptr)
	{
		if (go->info == e)
			return i;
		i++;
		go = go->next;
	}
	return -1;
}

//complexity: theta(1)
ListIterator SortedIndexedList::iterator()
{
	ListIterator it(*this);
	return it;
}
