#pragma once

#include "Node.h"
#include "helpers.h"

class Heap {
private:
    Node* heap[MAX_SIZE];
    bool is_max_heap;
    int count;
    Heap* second_heap;

    inline int getParentIndex(int index) { return (index - 1) / 2; }
    inline int getLeftChildIndex(int index) { return 2 * index + 1; }
    inline int getRightChildIndex(int index) { return 2 * index + 2; }

    void updateIndex(int, int);
    void fixHeapUp(int);
    void fixHeapDown(int);

public:
    Heap(bool);
    inline bool IsEmpty() const { return this->count == 0; }
    void MakeEmpty();
    Node* Extreme();
    void Insert(int, std::string, int);
    Node* DeleteExtreme();
};