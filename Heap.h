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

    void updateSelfIndexInSecondHeap(int);
    void fixHeapUp(int);
    void fixHeapDown(int);
    Node* deleteFromSelfOnly(int);
    int insertToSelfOnly(int, std::string);
    int findIndex(Node*);

public:
    Heap(bool);
    inline bool IsEmpty() const { return this->count == 0; }
    inline Node** getHeap() { return heap; }
    inline void setSecondHeap(Heap* value) { this->second_heap = value; }
    void MakeEmpty();
    Node* Extreme();
    void Insert(int, std::string);
    inline Node* DeleteExtreme() { return Delete(0); }
    Node* Delete(int);
};