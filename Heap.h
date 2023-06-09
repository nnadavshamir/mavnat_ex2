#pragma once

#include "Node.h"
#include "helpers.h"

class Heap {
private:
    Node heap[MAX_SIZE];
    bool is_max_heap;
    int count;
    Heap* second_heap;

    inline int getParentIndex(int index) { return (index - 1) / 2; }
    inline int getLeftChildIndex(int index) { return 2 * index + 1; }
    inline int getRightChildIndex(int index) { return 2 * index + 2; }

    void updateSelfIndexInSecondHeap(int);
    int fixHeapUp(int);
    void fixHeapDown(int);
    Node deleteFromSelfOnly(int);
    int insertToSelfOnly(int, std::string);
    Node Delete(int);

public:
    Heap(bool);
    inline bool IsEmpty() const { return this->count == 0; }
    inline Node* getHeap() { return heap; }
    inline void setSecondHeap(Heap* value) { this->second_heap = value; }
    inline int getSize() const { return this->count; }
    inline Node DeleteExtreme() { return Delete(0); }
    void MakeEmpty();
    Node Extreme();
    void Insert(int, std::string);
};