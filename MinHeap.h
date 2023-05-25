#pragma once
#include "Node.h"
#include "MaxHeap.h"

#define MAX_SIZE 100

class MinHeap {
private:
	Node data[MAX_SIZE];
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

