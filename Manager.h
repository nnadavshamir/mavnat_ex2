#pragma once
#include "Heap.h"

class Manager {
private:
	Heap upperMaxHeap;
	Heap upperMinHeap;
	Heap lowerMaxHeap;
	Heap lowerMinHeap;

public:
	Manager() : upperMaxHeap(Heap(true)), upperMinHeap(Heap(false)), lowerMaxHeap(Heap(true)), lowerMinHeap(Heap(false)) { }
	void Max();
	void DeleteMax();
	void Min();
	void DeleteMin();
	void MakeEmpty();
	void Insert(int priority, std::string value);
	void Median();
};

