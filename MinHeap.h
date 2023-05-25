#pragma once
#include "Node.h"

class MinHeap
{
private:
	Node data[100];
	int count;
	MaxHeap* linkedHeap;

public:
	Node Min();
	void DeleteMin();
	void Insert(int priority, std::string value);
	void FixHeap(int index);
	void MakeEmpty();
	bool IsEmpty();
};

