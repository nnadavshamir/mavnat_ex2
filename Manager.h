#pragma once
#include <string>
#include "MaxHeap.h"
#include "MinHeap.h"

class Manager
{
private:
	MaxHeap upperMaxHeap;
	MinHeap upperMinHeap;
	MaxHeap lowerMaxHeap;
	MinHeap lowerMinHeap;

public:
	void Max();
	void DeleteMax();
	void Min();
	void DeleteMin();
	void CreateEmpty();
	void Insert(int priority, std::string value);
	void Median();
};

