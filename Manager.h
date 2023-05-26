#pragma once
#include "Heap.h"

class Manager {
private:
	Heap upperMaxHeap;
	Heap upperMinHeap;
	Heap lowerMaxHeap;
	Heap lowerMinHeap;

	void fixUpperLowerIfNeeded();
public:
	Manager();
	void MakeEmpty();
	void Max();
	void Min();
	void DeleteMax();
	void DeleteMin();
	void Insert(int priority, std::string value);
	void Median();
	bool IsEmpty();
};

