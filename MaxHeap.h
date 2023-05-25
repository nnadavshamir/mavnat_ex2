#pragma once
#include "Node.h"
#include "helpers.h"
#include "MinHeap.h"

class MaxHeap {
private:
	MinHeap* linkedHeap;
	Node* heap[MAX_SIZE];
	int count;
	inline int getParentIndex(int index) { return (index - 1) / 2; }
	inline int getLeftChildIndex(int index) { return 2 * index + 1; }
	inline int getRightChildIndex(int index) { return 2 * index + 2; }

	void fixHeapUp(int);
	void fixHeapDown(int);

public:
	inline bool IsEmpty() const { return this->count == 0; }
	void MakeEmpty();
	Node Max();
	void DeleteMax();
	void Insert(int, std::string);
	void FixHeap(int);
};

