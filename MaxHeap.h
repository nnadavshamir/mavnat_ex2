#pragma once
#include "Node.h"

class MaxHeap
{
private:
	Node data[100];
	int count;
	MinHeap* linkedHeap;

public:
	Node Max();
	void DeleteMax();
	void Insert(int priority, std::string value);
	void FixHeap(int index);
	void MakeEmpty();
	bool IsEmpty();
};

