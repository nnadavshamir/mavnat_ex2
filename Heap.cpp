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

    this->count = 0;
}

void Heap::fixHeapUp(int index) {
    if (index == 0)
        return;

    int parent_index = getParentIndex(index);

    if ((this->is_max_heap && this->heap[parent_index]->priority < this->heap[index]->priority)
        || (!this->is_max_heap && this->heap[parent_index]->priority > this->heap[index]->priority)) {
        swap(this->heap[parent_index], this->heap[index]);
        updateIndex(this->heap[parent_index]->second_heap_index, parent_index);
        updateIndex(this->heap[index]->second_heap_index, index);
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
        updateIndex(this->heap[extreme_index]->second_heap_index, extreme_index);
        updateIndex(this->heap[index]->second_heap_index, index);
        fixHeapDown(extreme_index);
    }
}

void Heap::updateIndex(int node_to_update_index, int _index) {
    if (node_to_update_index >= 0)
        this->heap[node_to_update_index]->second_heap_index = _index;
}

Node* Heap::Extreme() {
    if (this->count == 0) return;

    return this->heap[0];
}

Node* Heap::DeleteExtreme() {
    if (IsEmpty()) {
        std::cout << "Heap is empty!" << std::endl;
        return;
    }

    swap(this->heap[0], this->heap[this->count - 1]);
    updateIndex(this->heap[0]->second_heap_index, 0);
    Node* removed = this->heap[this->count - 1];
    
    // TODO: Remove from second list

    this->count--;
    fixHeapDown(0);
    return removed;
}

void Heap::Insert(int _priority, std::string _data) {
    Node *new_node = new Node(_priority, _data, NOT_SET);
    this->heap[this->count++] = new_node;
    fixHeapUp(this->count - 1);

    // TODO: Add to second heap
}