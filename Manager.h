#pragma once
#include "Heap.h"

class Manager {
private:
	Heap upperMaxHeap;
	Heap upperMinHeap;
	Heap lowerMaxHeap;
	Heap lowerMinHeap;

public:
	Manager();
	void MakeEmpty();
	Node Max();
	Node Min();
	void DeleteMax();
	void DeleteMin();
	void Insert(int priority, std::string value);
	void Median();
};

