#include "Heap.h"

Heap::Heap(bool _is_max_heap) : is_max_heap(_is_max_heap), second_heap(nullptr), count(0) {
    for (int i = 0; i < MAX_SIZE; i++)
        this->heap[i] = nullptr;
}

void Heap::MakeEmpty() {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (this->heap[i]) delete heap[i];

        this->heap[i] = nullptr;
    }
    
    setSecondHeap(nullptr);
    this->count = 0;
}

void Heap::fixHeapUp(int index) {
    if (index == 0)
        return;

    int parent_index = getParentIndex(index);

    if ((this->is_max_heap && this->heap[parent_index]->priority < this->heap[index]->priority)
        || (!this->is_max_heap && this->heap[parent_index]->priority > this->heap[index]->priority)) {
        swap(this->heap[parent_index], this->heap[index]);
        updateSelfIndexInSecondHeap(parent_index);
        updateSelfIndexInSecondHeap(index);
        fixHeapUp(parent_index);
    }
}

void Heap::fixHeapDown(int index) {
    if (index == count)
        return;

    int left_child_index = getLeftChildIndex(index);
    int right_child_index = getRightChildIndex(index);
    int extreme_index = index;

    if (left_child_index < this->count &&
        ((this->is_max_heap && this->heap[left_child_index]->priority > this->heap[extreme_index]->priority))
        || (!this->is_max_heap && this->heap[left_child_index]->priority < this->heap[extreme_index]->priority))
        extreme_index = left_child_index;

    if (right_child_index < this->count &&
        ((this->is_max_heap && this->heap[right_child_index]->priority > this->heap[extreme_index]->priority))
        || (!this->is_max_heap && this->heap[right_child_index]->priority < this->heap[extreme_index]->priority))
        extreme_index = right_child_index;

    if (extreme_index != index) {
        swap(this->heap[extreme_index], this->heap[index]);
        updateSelfIndexInSecondHeap(extreme_index);
        updateSelfIndexInSecondHeap(index);
        fixHeapDown(extreme_index);
    }
}

void Heap::updateSelfIndexInSecondHeap(int self) {
    if (!this->second_heap) return;

    if (self >= 0)
        this->second_heap->getHeap()[this->heap[self]->second_heap_index]->second_heap_index = self;
}

Node* Heap::Extreme() {
    if (this->count == 0) return;

    return this->heap[0];
}

void Heap::Insert(int _priority, std::string _data) {
    Node *new_node = new Node(_priority, _data, NOT_SET);
    this->heap[this->count++] = new_node;
    fixHeapUp(this->count - 1);

    // TODO: Add to second heap
}

Node* Heap::deleteFromSelfOnly(int index) {
    if (index >= this->count) {
        std::cout << "Heap is empty!" << std::endl;
        return;
    }

    swap(*this->heap[index], *this->heap[this->count - 1]);
    updateSelfIndexInSecondHeap(index);
    updateSelfIndexInSecondHeap(count - 1);
    Node* removed = this->heap[this->count - 1];

    this->count--;
    fixHeapDown(index);
    return removed;
}

Node* Heap::Delete(int index) {
    Node* removed = deleteFromSelfOnly(index);
    this->second_heap->deleteFromSelfOnly(removed->second_heap_index);

    return removed;
}
