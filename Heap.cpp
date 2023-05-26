#include "Heap.h"

Heap::Heap(bool _is_max_heap) : is_max_heap(_is_max_heap), second_heap(nullptr), count(0) { }

void Heap::MakeEmpty() {  
    setSecondHeap(nullptr);
    this->count = 0;
}

void Heap::fixHeapUp(int index) {
    if (index == 0)
        return;

    int parent_index = getParentIndex(index);

    if ((this->is_max_heap && this->heap[parent_index].priority < this->heap[index].priority)
        || (!this->is_max_heap && this->heap[parent_index].priority > this->heap[index].priority)) {
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
        ((this->is_max_heap && this->heap[left_child_index].priority > this->heap[extreme_index].priority))
        || (!this->is_max_heap && this->heap[left_child_index].priority < this->heap[extreme_index].priority))
        extreme_index = left_child_index;

    if (right_child_index < this->count &&
        ((this->is_max_heap && this->heap[right_child_index].priority > this->heap[extreme_index].priority))
        || (!this->is_max_heap && this->heap[right_child_index].priority < this->heap[extreme_index].priority))
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
        this->second_heap->getHeap()[this->heap[self].second_heap_index].second_heap_index = self;
}

Node Heap::Extreme() {
    if (this->count == 0) return Node();

    return this->heap[0];
}

void Heap::Insert(int _priority, std::string _data) {
    int self_node_index = insertToSelfOnly(_priority, _data);
    int second_heap_node_index = this->second_heap->insertToSelfOnly(_priority, _data);
    
    this->heap[self_node_index].second_heap_index = second_heap_node_index;
    this->second_heap->getHeap()[second_heap_node_index].second_heap_index = self_node_index;
}

int Heap::findIndex(Node& node_to_search) {
    // TODO: Change function to acheive O(lg n) complexity

    bool found = false;
    int i = 0;

    for (; i < this->count && !found; i++)
        if (this->heap[i] == node_to_search)
            found = true;

    return found ? i - 1 : NOT_FOUND;
}

int Heap::insertToSelfOnly(int _priority, std::string _data) {
    Node new_node = Node(_priority, _data, NOT_SET);
    this->heap[this->count++] = new_node;
    fixHeapUp(this->count - 1);

    return findIndex(new_node);
}

Node Heap::deleteFromSelfOnly(int index) {
    if (index >= this->count) {
        std::cout << "Heap is empty!" << std::endl;
        return Node();
    }

    swap(this->heap[index], this->heap[this->count - 1]);
    updateSelfIndexInSecondHeap(index);
    updateSelfIndexInSecondHeap(count - 1);
    Node removed = this->heap[this->count - 1];

    this->count--;
    fixHeapDown(index);
    return removed;
}

Node Heap::Delete(int index) {
    Node removed = deleteFromSelfOnly(index);
    this->second_heap->deleteFromSelfOnly(removed.second_heap_index);

    return removed;
}
